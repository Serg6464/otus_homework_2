#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>
#include <logexceptioncommand.h>
#include <memory>

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;

class CMockLogWriter: public ILogWriter
{
    public:
    MOCK_METHOD( void, Write, (std::string str));
};

class LogExException1: public IException
{
    public:
    MOCK_METHOD( std::string, what, ());
};

TEST(logexceptioncommand, basic_test)
{
    std::shared_ptr<CMockLogWriter> Log = std::make_shared<CMockLogWriter>();
    std::shared_ptr<LogExException1> except = std::make_shared<LogExException1>();
    std::shared_ptr<LogExceptionCommand> cmd = std::make_shared<LogExceptionCommand>(Log, except);

    EXPECT_CALL( *except, what() )
        .WillOnce(Return("message to write"));

    EXPECT_CALL( *Log, Write(std::string("message to write")) )
        .Times(1);;

    cmd->Execute();
}