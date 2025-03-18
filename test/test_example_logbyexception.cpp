#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <commandprocessor.h>
#include <mock_icommand.h>
#include <mock_icommandqueue.h>
#include <mock_iexceptionhandler.h>
#include <mock_logwriter.h>

#include <addcommand.h>
#include <logexceptioncommand.h>

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;


class LogByExceptionException1: public IException
{
    public:
    MOCK_METHOD( std::string, what, ());
};

TEST(commandprocessor, log_by_exception_test)
{
    std::shared_ptr<CMockCommandQueue> testqueue = std::make_shared<CMockCommandQueue>();
    std::shared_ptr<CMockExceptionHandler> testexceptions = std::make_shared<CMockExceptionHandler>();
    std::shared_ptr<CMockLogWriter> Log = std::make_shared<CMockLogWriter>();
    std::shared_ptr<LogByExceptionException1> exception = std::make_shared<LogByExceptionException1>();

    EXPECT_CALL( *testexceptions, GetHandler(_, _))
        .WillOnce(Return( std::make_shared<AddCmdCommand>( 
                                            std::make_shared<LogExceptionCommand>( Log, exception),
                                            testqueue)
                              ));

    EXPECT_CALL( *testqueue, AddCommand(_) )
        .Times(1);


    testexceptions->GetHandler(nullptr, nullptr)->Execute();
}