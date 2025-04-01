#ifndef __MACROCOMMAND_H__
#define __MACROCOMMAND_H__

#include <icommand.h>
#include <icommandqueue.h>
#include <memory>

class MacroCommand: public ICommand
{
    std::shared_ptr<ICommandQueue> m_Commands;

public:
    MacroCommand(std::shared_ptr<ICommandQueue> commands);

    void Execute() const;
};


#endif