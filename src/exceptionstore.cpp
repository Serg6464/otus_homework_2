#include <exceptionstore.h>
#include <logcommand.h>

std::map<const char *, handler_type_func_pointer> CExceptionStore::_map_Handlers; 

std::shared_ptr<ICommand> DefaultHandler(std::shared_ptr<ICommand> cmd, const std::exception &excp)
{
    return std::shared_ptr<LogCommand>(new LogCommand(cmd, excp));
}

std::shared_ptr<ICommand> CExceptionStore::Handle(std::shared_ptr<ICommand> cmd, const std::exception &exception)
{
    std::string key = MakeExceptionName( cmd, exception );
    if( _map_Handlers.count(key.c_str()) )
    {
        return _map_Handlers[key.c_str()](cmd, exception);
    } else {
        //Default handler?
        return std::shared_ptr<ICommand>(0);
    }
}

void CExceptionStore::Register(char *exception_name, handler_type_func_pointer pHandler)
{
    _map_Handlers[exception_name] = pHandler;
}