#include <commandprocessor.h>
#include <iexception.h>

void CommandProcessor::Execute()
{
    if( _commands == nullptr ) return;
    if( _exception_handler == nullptr ) return;

    while(1)
    {
        std::shared_ptr<ICommand> cmd = _commands->GetCommand();
        if( cmd == nullptr ) return;
        try
        {
            cmd->Execute();
        }
        catch(IException * e)
        {
            std::shared_ptr<ICommand> newCmd = _exception_handler->GetHandler( cmd, std::shared_ptr<IException>(e));
            if( newCmd != nullptr )
            {
                newCmd->Execute();
            }
        }
        
        /* code */
    } 
    
}