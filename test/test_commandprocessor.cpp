#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <commandprocessor.h>
#include <mock_icommand.h>
#include <mock_icommandqueue.h>
#include <mock_iexceptionhandler.h>

#include <repeatedcommand.h>
#include <repeatcommandhandler.h>
#include <logexceptioncommand.h>
#include <mock_logwriter.h>

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;

TEST(commandprocessor, simple_run)
{
    std::shared_ptr<CMockCommandQueue> testqueue = std::make_shared<CMockCommandQueue>();
    std::shared_ptr<CMockExceptionHandler> testexceptions = std::make_shared<CMockExceptionHandler>();
    std::shared_ptr<CMockCommand> cmd = std::make_shared<CMockCommand>();

    CommandProcessor Processor(testqueue, testexceptions);

    EXPECT_CALL( *testqueue, GetCommand() )
        .WillOnce(Return( cmd))
        .WillOnce(Return( nullptr));

    EXPECT_CALL( *cmd, Execute() ) .Times(1);

    Processor.Execute();
}

class Exception1: public IException
{
    public:
    MOCK_METHOD( std::string, what, ());
};

TEST(commandprocessor, step3_test_exceptionhandler)
{
    std::shared_ptr<CMockCommandQueue> testqueue = std::make_shared<CMockCommandQueue>();
    std::shared_ptr<CMockExceptionHandler> testexceptions = std::make_shared<CMockExceptionHandler>();
    std::shared_ptr<CMockCommand> cmd = std::make_shared<CMockCommand>();
    Exception1 *exception = new Exception1;
    
    CommandProcessor Processor(testqueue, testexceptions);

    EXPECT_CALL( *testqueue, GetCommand() )
        .WillOnce(Return( cmd))
        .WillOnce(Return( nullptr));

    EXPECT_CALL( *testexceptions, GetHandler(_, _))
        .WillOnce(Return(nullptr));

    EXPECT_CALL( *cmd, Execute() ) .WillOnce(Throw(exception));

    EXPECT_NO_THROW(Processor.Execute());
}
ACTION_P2(ReturnWriteLogExceptionHandler, p1_LogObject, p2_CommandQueue) 
{ return std::make_shared<AddCmdCommand>(std::make_shared<LogExceptionCommand>(p1_LogObject, arg1), p2_CommandQueue); }
ACTION_P(ReturnRepeatHandler, p1) { return std::make_shared<RepeatCommandHandler>(arg0, p1); }

TEST(commandprocessor, step8_if_throw_repeat_log)
{
    std::shared_ptr<CMockCommandQueue> testqueue = std::make_shared<CMockCommandQueue>();
    std::shared_ptr<CMockExceptionHandler> testexceptions = std::make_shared<CMockExceptionHandler>();
    std::shared_ptr<CMockCommand> cmd = std::make_shared<CMockCommand>();
    Exception1 *exception = new Exception1;
    Exception1 *exception1 = new Exception1;
    std::shared_ptr<CMockLogWriter> Log = std::make_shared<CMockLogWriter>();


//AddCommand args
    std::shared_ptr<ICommand> add_cmd1;
    std::shared_ptr<ICommand> add_cmd2;

    CommandProcessor Processor(testqueue, testexceptions);

    EXPECT_CALL( *testqueue, GetCommand() )
        .WillOnce(Return( cmd))
        .WillOnce( [&add_cmd1](){return add_cmd1; })
        .WillOnce( [&add_cmd2](){return add_cmd2; })
        .WillOnce(Return( nullptr));

    EXPECT_CALL( *testexceptions, GetHandler(_, _))
        .WillOnce( ReturnRepeatHandler(testqueue) )
        .WillOnce( ReturnWriteLogExceptionHandler(Log, testqueue))
        ;

    EXPECT_CALL( *testqueue, AddCommand(_) )
        .WillOnce(testing::SaveArg<0>(&add_cmd1))
        .WillOnce(testing::SaveArg<0>(&add_cmd2));

    EXPECT_CALL( *cmd, Execute() ) 
        .WillOnce(Throw(exception))
        .WillOnce(Throw(exception1));

    EXPECT_CALL( *Log, Write(_) )
        .Times(1);

    EXPECT_NO_THROW(Processor.Execute());
}