#include <addcmd_command.h>
#include <commandprocessor.h>

void AddCmdCommand::Execute() const
{
    CommandProcessor::AppendCommand(_command);
}