#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iexceptionhandler.h>

class CMockExceptionHandler:public IExceptionHandler
{
    public:
     MOCK_METHOD( std::shared_ptr<ICommand>, GetHandler, (std::shared_ptr<ICommand>  pCommand, std::shared_ptr<IException>  pException), (override) );
};