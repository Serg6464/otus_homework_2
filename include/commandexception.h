#ifndef __COMMANDEXCEPTION_H__
#define __COMMANDEXCEPTION_H__

#include <memory>
#include <iexception.h>
#include <icommand.h>

class CommandException: public IException
{
    std::shared_ptr<ICommand>  _command;
    std::shared_ptr<IException>  _exception;
public:
    virtual ~CommandException() = default;

    CommandException(std::shared_ptr<ICommand>  command, std::shared_ptr<IException>  exception)
    {
        _command = command; 
        _exception = exception;
    }
    std::string what()
    {
        return std::string("Command failed ") + _exception->what(); 
    };
}
;

#endif