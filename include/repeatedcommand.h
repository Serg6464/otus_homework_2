#ifndef __REPEATEDCOMMAND_H__
#define __REPEATEDCOMMAND_H__

#include <icommand.h>
#include <iexception.h>
#include <repeatexception.h>
#include <memory>

//Команда, которая повторяет команду если она выбрасывает исключение
class RepeatedCommand: public ICommand
{
    std::shared_ptr<ICommand> _command;
    public:
    ~RepeatedCommand() = default;
    RepeatedCommand(std::shared_ptr<ICommand> cmd)
    {
        _command = cmd;
    };
    void Execute() const
    {
        if( _command != nullptr )
        {
            try
            {
                _command->Execute();
            }
            catch(IException *e)
            {
                throw new RepeatException(_command, std::shared_ptr<IException>(e));
            }
        }
    };
};

#endif