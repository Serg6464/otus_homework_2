#include <exception_helpers.h>
#include <logcommand.h>
#include <addcmd_command.h>

//обрвботчик записывающий исключение в лог
std::shared_ptr<ICommand> DefaultHandler(std::shared_ptr<ICommand> cmd, const IException &excp)
{
    return std::shared_ptr<LogCommand>(new LogCommand(cmd, excp));
}

//обработчик добавляющий команду записи в лог в список команд
std::shared_ptr<ICommand> AddLogToCommandsHandler(std::shared_ptr<ICommand> cmd, const IException &excp)
{
    return std::shared_ptr<AddCmdCommand>(new AddCmdCommand(std::shared_ptr<LogCommand>(new LogCommand(cmd, excp))));
}