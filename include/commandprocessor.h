#ifndef __COMMANDPROCESSOR_H__
#define __COMMANDPROCESSOR_H__

#include <icommand.h>
#include <queue>
#include <memory>

class CommandProcessor
{
    static std::queue <std::shared_ptr<ICommand>>_commands;
    public:
    ~CommandProcessor() = default;
    CommandProcessor()
    {
        _commands = {};
    }

    static void Execute();
    static void AppendCommand(std::shared_ptr<ICommand>);
};

#endif