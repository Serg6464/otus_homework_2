#ifndef __ADDCMD_COMMAND_H__
#define __ADDCMD_COMMAND_H__

#include <icommand.h>
#include <memory>

//Команда, которая добавляет выбранную команду в очередь команд
class AddCmdCommand: public ICommand
{
    std::shared_ptr<ICommand> _command;
    public:
    ~AddCmdCommand() = default;
    AddCmdCommand(std::shared_ptr<ICommand> cmd)
    {
        _command = cmd;
    }
    void Execute() const;
};



#endif