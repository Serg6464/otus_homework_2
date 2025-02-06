#ifndef __EXCEPTION_STORE_H__
#define __EXCEPTION_STORE_H__

#include <map>
#include <memory>
#include <icommand.h>
#include <typeinfo>
#include <string>
#include <iexception.h>

//таблица обработчиков исключений

typedef std::shared_ptr<ICommand> handler_type_func(std::shared_ptr<ICommand>, const IException &);

typedef handler_type_func * handler_type_func_pointer;


template<class input1, class input2>
std::string MakeExceptionName(input1 CommandType, input2 ExceptionType){
    return std::string(typeid(CommandType).name())+typeid(ExceptionType).name();
}

class CExceptionStore
{
    static std::map<const char *, handler_type_func_pointer> _map_Handlers;

    public:
    ~CExceptionStore() = default;

    static std::shared_ptr<ICommand> Handle(std::shared_ptr<ICommand>, const IException &exception);

    //использовать с MakeExceptionName для преобразования Типа команды и типа исключения в exception_name
    static void Register(char *exception_name, handler_type_func_pointer pHandler);

};

#endif