#ifndef __ADDCMD_COMMAND_H__
#define __ADDCMD_COMMAND_H__

#include <icommand.h>
#include <icommandqueue.h>
#include <memory>

//Команда, которая добавляет выбранную команду в очередь команд
class AddCmdCommand: public ICommand
{
    std::shared_ptr<ICommand> _command;
    std::shared_ptr<ICommandQueue> _cmdqueue;
    public:
    ~AddCmdCommand() = default;
    AddCmdCommand(std::shared_ptr<ICommand> cmd, std::shared_ptr<ICommandQueue> cmdqueue)
    {
        _command = cmd;
        _cmdqueue = cmdqueue;
    };
    void Execute() const
    {
        if( _cmdqueue != nullptr )
        {
            _cmdqueue->AddCommand(_command);
        }
    };
};



#endif