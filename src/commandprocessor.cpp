#include <commandprocessor.h>
#include <exceptionstore.h>
#include <iexception.h>

std::queue <std::shared_ptr<ICommand>> CommandProcessor::_commands = {};

void CommandProcessor::Execute()
{
    while (!_commands.empty())
    {
        std::shared_ptr<ICommand> cmd;        
        try
        {

            cmd = _commands.front();
            _commands.pop();
            cmd->Execute();
        }
        catch(const IException& e)
        {
            std::shared_ptr<ICommand> newCmd = CExceptionStore::Handle( cmd, e);
            if( newCmd != nullptr )
            {
                newCmd->Execute();
            }
        }
        
        /* code */
    }
    
}

void CommandProcessor::AppendCommand(std::shared_ptr<ICommand> cmd)
{
    if( cmd != nullptr )
    {
        _commands.push(cmd);
    }
}
