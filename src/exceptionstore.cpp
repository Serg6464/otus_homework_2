#include <exceptionstore.h>
#include <exception_helpers.h>

std::map<const char *, handler_type_func_pointer> CExceptionStore::_map_Handlers; 



std::shared_ptr<ICommand> CExceptionStore::Handle(std::shared_ptr<ICommand> cmd, const IException &exception)
{
    std::string key = MakeExceptionName( cmd, exception );
    if( _map_Handlers.count(key.c_str()) )
    {
        return _map_Handlers[key.c_str()](cmd, exception);
    } else {
        //Default handler?
        return DefaultHandler(cmd, exception);
    }
}

void CExceptionStore::Register(char *exception_name, handler_type_func_pointer pHandler)
{
    _map_Handlers[exception_name] = pHandler;
}