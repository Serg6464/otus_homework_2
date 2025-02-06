#include <logcommand.h>

std::shared_ptr<ILogWriter> LogCommand::_logwriter;

void LogCommand::Execute() const
{
    if( _logwriter != nullptr )
    {
        _logwriter->WriteToLog(_message.c_str());
    }    
}

