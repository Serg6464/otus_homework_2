#ifndef __ICOMMANDQUEUE_H__
#define __ICOMMANDQUEUE_H__

#include <memory>
#include <icommand.h>

class ICommandQueue
{
public:
    virtual ~ICommandQueue() = default;

    /*!
        \return Первая команда из очереди. Если очередь пуста, то возвращает nullptr.
    */
    virtual std::shared_ptr<ICommand> GetCommand() = 0;
};

#endif