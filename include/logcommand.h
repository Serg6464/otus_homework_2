#ifndef __LOGCOMMAND_H__
#define __LOGCOMMAND_H__

#include <icommand.h>
#include <string>
#include <memory>
#include <ilogwriter.h>

class LogCommand: public ICommand
{
    std::shared_ptr<ILogWriter> _logwriter;
    std::string _message;
    public:
    ~LogCommand() = default;
    LogCommand(std::shared_ptr<ILogWriter> logwriter, std::string message)
    {
        _logwriter = logwriter;
        _message = message;
    }
    virtual void Execute() const
    {
        if(_logwriter != nullptr )
        {
            _logwriter->Write(_message);
        }
    }
};

#endif