#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <mock_icommand.h>
#include <mock_icommandqueue.h>
#include <mock_icommand.h>
#include <iexception.h>

#include <macrocommand.h>
#include <commandexception.h>

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;


TEST(macrocommand, simple_run)
{
    std::shared_ptr<CMockCommandQueue> testqueue = std::make_shared<CMockCommandQueue>();
    std::shared_ptr<CMockCommand> pcmd1 = std::make_shared<CMockCommand>();
    std::shared_ptr<CMockCommand> pcmd2 = std::make_shared<CMockCommand>();
    MacroCommand macro(testqueue);
    
    EXPECT_CALL( *testqueue, GetCommand() )
        .WillOnce(Return( pcmd1))
        .WillOnce(Return( pcmd2))
        .WillOnce(Return( nullptr));


    macro.Execute();
}

class TestMacroException: public IException
{
    public:
    MOCK_METHOD( std::string, what, ());
};

TEST(macrocommand, break_by_exception)
{
    std::shared_ptr<CMockCommandQueue> testqueue = std::make_shared<CMockCommandQueue>();
    std::shared_ptr<CMockCommand> pcmd1 = std::make_shared<CMockCommand>();
    TestMacroException *exception = new TestMacroException;
    MacroCommand macro(testqueue);
    
    EXPECT_CALL( *testqueue, GetCommand() )
        .WillOnce(Return( pcmd1));

    EXPECT_CALL( *pcmd1, Execute() ).WillOnce(Throw(exception));

    try
    {
        macro.Execute();
        FAIL();
    }
    catch(IException *exception)
    {
        EXPECT_NE(dynamic_cast<CommandException*>(exception), nullptr);
        delete exception;
    }
}