#include <macrocommand.h>
#include <commandexception.h>

MacroCommand::MacroCommand(std::shared_ptr<ICommandQueue> commands)
    : m_Commands(commands)
{
}

void MacroCommand::Execute() const
{
    if (m_Commands == nullptr)
        return;

    std::shared_ptr<ICommand> pCmd;
    while (pCmd = m_Commands->GetCommand())
    {
        try
        {
            pCmd->Execute();
        }
        catch(IException *e)
        {
            throw new CommandException(pCmd, std::shared_ptr<IException>(e));    
        }
    }
}