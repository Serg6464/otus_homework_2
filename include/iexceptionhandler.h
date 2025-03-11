#ifndef __IEXCEPTIONHANDLER_H__
#define __IEXCEPTIONHANDLER_H__

#include <memory>
#include <icommand.h>
#include <iexception.h>

class IExceptionHandler
{
public:
    virtual ~IExceptionHandler() = default;

    virtual std::shared_ptr<ICommand> GetHandler(std::shared_ptr<ICommand>  pCommand, std::shared_ptr<IException>  pException) = 0;
};

#endif