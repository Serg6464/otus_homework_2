#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>
#include <logcommand.h>
#include <memory>

class CMockLogWriter: public ILogWriter
{
    public:
    MOCK_METHOD( void, Write, (std::string str));
};

TEST(logcommand, basic_test)
{
    std::shared_ptr<CMockLogWriter> Log = std::make_shared<CMockLogWriter>();
    std::shared_ptr<LogCommand> cmd = std::make_shared<LogCommand>(Log, "message to write");

    EXPECT_CALL( *Log, Write(std::string("message to write")) )
        .Times(1);;

    cmd->Execute();
}