#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <icommandqueue.h>

class CMockCommandQueue:public ICommandQueue
{
    public:
     MOCK_METHOD( std::shared_ptr<ICommand>, GetCommand, (), (override));
     MOCK_METHOD( void, AddCommand, (std::shared_ptr<ICommand>), (override));
};