#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <commandprocessor.h>
#include <mock_icommand.h>
#include <mock_icommandqueue.h>
#include <mock_iexceptionhandler.h>

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