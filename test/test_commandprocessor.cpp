#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>
#include <stdexcept>
#include <commandprocessor.h>
#include <logcommand.h>

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;

class CommandMock: public ICommand
{
    public:
    
    MOCK_METHOD(void, Execute, (), (const, override));
};

class LogWriterMock: public ILogWriter
{
    public:

    MOCK_METHOD(void, WriteToLog, (const char *), (override));
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

TEST(commandprocessor, testlogcommand_by_exception)
{
    CommandProcessor CmdProc;
    std::shared_ptr<CommandMock> cmd (new CommandMock);
    
    std::shared_ptr<LogWriterMock> pTestLogWriter (new LogWriterMock);
    LogCommand::SelectLogStore(pTestLogWriter);

    CmdProc.AppendCommand(cmd);

    ON_CALL( *cmd, Execute()).WillByDefault(Throw(IException("test exception generate")));
 
    EXPECT_CALL( *pTestLogWriter, WriteToLog(_));

    EXPECT_NO_THROW( CmdProc.Execute() );

}