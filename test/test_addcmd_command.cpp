#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>
#include <stdexcept>
#include <commandprocessor.h>
#include <addcmd_command.h>

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;

class CFakeCommand:public ICommand
{
    public:
     MOCK_METHOD( void, Execute, (), (const));
};

TEST(addcmd_command, execute)
{
    std::shared_ptr<CFakeCommand> fakeCommand(new CFakeCommand());
    //AddCmdCommand addcmd(fakeCommand);

    EXPECT_CALL( *fakeCommand, Execute()).Times(1);

    CommandProcessor::AppendCommand(std::shared_ptr<AddCmdCommand>(new AddCmdCommand(fakeCommand)));
    CommandProcessor::Execute();


}