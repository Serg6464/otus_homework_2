#ifndef __REPEATCOMMANDHANDLER_H__
#define __REPEATCOMMANDHANDLER_H__

#include <memory>
#include <icommand.h>
#include <iexception.h>
#include <repeatedcommand.h>
#include <addcommand.h>
#include <icommandqueue.h>

class RepeatCommandHandler:public ICommand
{
    std::shared_ptr<AddCmdCommand> _addcommand;

public:
    ~RepeatCommandHandler() = default;
    RepeatCommandHandler(std::shared_ptr<ICommand> cmd, std::shared_ptr<ICommandQueue> cmdqueue)
    {
        _addcommand = std::make_shared<AddCmdCommand>(std::make_shared<RepeatedCommand>(cmd), cmdqueue); 
    }

    virtual void Execute() const
    {
        _addcommand->Execute();
    }
};

#endif