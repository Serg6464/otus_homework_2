#ifndef __REPEATEXCEPTION_H__
#define __REPEATEXCEPTION_H__

#include <memory>
#include <iexception.h>
#include <icommand.h>

class RepeatException: public IException
{
    std::shared_ptr<ICommand>  _command;
    std::shared_ptr<IException>  _exception;
public:
    virtual ~RepeatException() = default;

    RepeatException(std::shared_ptr<ICommand>  command, std::shared_ptr<IException>  exception)
    {
        _command = command; 
        _exception = exception;
    }
    std::string what()
    {
        return std::string("Repeat failed ") + _exception->what(); 
    };
}
;

#endif