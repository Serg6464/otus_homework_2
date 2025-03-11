#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <icommand.h>

class CMockCommand:public ICommand
{
    public:
     MOCK_METHOD( void, Execute, (), (const));
};