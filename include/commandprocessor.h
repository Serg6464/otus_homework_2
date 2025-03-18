#ifndef __COMMANDPROCESSOR_H__
#define __COMMANDPROCESSOR_H__

#include <iexceptionhandler.h>
#include <icommandqueue.h>
#include <memory>

class CommandProcessor
{
    std::shared_ptr<ICommandQueue> _commands;
    std::shared_ptr<IExceptionHandler> _exception_handler;
    public:
    ~CommandProcessor() = default;
    CommandProcessor(std::shared_ptr<ICommandQueue> commands, std::shared_ptr<IExceptionHandler> exception_handler)
    {
        _commands = commands;
        _exception_handler = exception_handler;
    }

    void Execute();
};

#endif