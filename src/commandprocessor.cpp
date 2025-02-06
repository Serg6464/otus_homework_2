#include <commandprocessor.h>

std::queue <std::shared_ptr<ICommand>> CommandProcessor::_commands = {};

void CommandProcessor::Execute()
{
    while (!_commands.empty())
    {
        try
        {
            std::shared_ptr<ICommand> cmd = _commands.front();
            _commands.pop();
            cmd->Execute();
        }
        catch(const std::exception& e)
        {
            //exception!!!
        }
        
        /* code */
    }
    
}

void CommandProcessor::AppendCommand(std::shared_ptr<ICommand> cmd)
{
    _commands.push(cmd);
}
