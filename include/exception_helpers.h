#ifndef __EXCEPTION_HELPERS_H_
#define __EXCEPTION_HELPERS_H_
//функции обёртки для handlers обработки исключений

#include <exceptionstore.h>

//обрвботчик записывающий исключение в лог
std::shared_ptr<ICommand> DefaultHandler(std::shared_ptr<ICommand> cmd, const IException &excp);

//обработчик добавляющий команду записи в лог в список команд
std::shared_ptr<ICommand> AddLogToCommandsHandler(std::shared_ptr<ICommand> cmd, const IException &excp);

#endif