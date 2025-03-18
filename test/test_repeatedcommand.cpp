#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>
#include <mock_icommand.h>
#include <repeatedcommand.h>
#include <memory>

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;

class RepeatTestException1: public IException
{
    public:
    MOCK_METHOD( std::string, what, ());
};

TEST(repeatedcommand, basic_test)
{
    RepeatTestException1 except;
    CMockCommand cmd;
    std::shared_ptr<RepeatedCommand> repeatedcmd = std::make_shared<RepeatedCommand>(std::shared_ptr<CMockCommand>(&cmd));

    EXPECT_CALL( cmd, Execute() )
        .WillOnce(Throw(&except));
       

    EXPECT_THROW(repeatedcmd->Execute(), RepeatException *);
}