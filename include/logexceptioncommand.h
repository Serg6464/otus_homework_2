#ifndef __LOGECEPTIONCOMMAND_H__
#define __LOGECEPTIONCOMMAND_H__

#include <icommand.h>
#include <logcommand.h>
#include <iexception.h>
#include <memory>

class LogExceptionCommand: public ICommand
{
    std::shared_ptr<ILogWriter> _logwriter;
    std::shared_ptr<IException> _exception;

    public:
    ~LogExceptionCommand() = default;
    LogExceptionCommand( std::shared_ptr<ILogWriter> logwriter,
                        std::shared_ptr<IException> exception)
    { _logwriter = logwriter; _exception = exception; };

    virtual void Execute() const
    {
        if( _logwriter != nullptr)
            _logwriter->Write( _exception->what() );
    }

};

#endif