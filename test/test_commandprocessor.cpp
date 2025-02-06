#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>
#include <stdexcept>
#include <commandprocessor.h>

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;

class CommandMock: public ICommand
{
    public:
    
    MOCK_METHOD(void, Execute, (), (const, override));
};

TEST(commandprocessor, simplework)
{
    CommandProcessor CmdProc;
    std::shared_ptr<CommandMock> cmd (new CommandMock);
    std::shared_ptr<CommandMock> cmd2 (new CommandMock);

    CmdProc.AppendCommand(cmd);
    CmdProc.AppendCommand(cmd2);

    EXPECT_CALL( *cmd, Execute()).WillOnce(Return());
    EXPECT_CALL( *cmd2, Execute()).WillOnce(Return());

    CmdProc.Execute();

}