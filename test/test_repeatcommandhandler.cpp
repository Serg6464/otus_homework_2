#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <commandprocessor.h>
#include <mock_icommand.h>
#include <mock_icommandqueue.h>
#include <mock_iexceptionhandler.h>
#include <mock_logwriter.h>

#include <addcommand.h>
#include <repeatcommandhandler.h>

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;


class LogByExceptionException1: public IException
{
    public:
    MOCK_METHOD( std::string, what, ());
};

TEST(commandprocessor, repeat_by_exception_handler)
{
    std::shared_ptr<CMockCommandQueue> testqueue = std::make_shared<CMockCommandQueue>();
    std::shared_ptr<CMockExceptionHandler> testexceptions = std::make_shared<CMockExceptionHandler>();
    std::shared_ptr<LogByExceptionException1> exception = std::make_shared<LogByExceptionException1>();

    std::shared_ptr<RepeatCommandHandler> repeatHandler = std::make_shared<RepeatCommandHandler>(nullptr, testqueue);
    EXPECT_CALL( *testexceptions, GetHandler(_,_))
        .WillOnce(Return( repeatHandler));

    EXPECT_CALL( *testqueue, AddCommand(_) )
        .Times(1);


    testexceptions->GetHandler(nullptr, nullptr)->Execute();
}