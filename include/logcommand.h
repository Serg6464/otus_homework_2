#ifndef __LOGCOMMAND_H__
#define __LOGCOMMAND_H__

#include <icommand.h>
#include <memory>
#include <string>
#include <ilogwriter.h>
#include <exception>
#include <typeinfo>

class LogCommand: public ICommand
{
    std::string _message;

    static std::shared_ptr<ILogWriter> _logwriter;
    public:
    LogCommand(std::shared_ptr<ICommand>cmd, const std::exception &exception)
    {
        _message = std::string(typeid(cmd).name())+":"+typeid(exception).name()+exception.what();
    };
    static void SelectLogStore( std::shared_ptr<ILogWriter> logstore)
    {
        _logwriter = logstore;
    }
    void Execute() const;
};

#endif
