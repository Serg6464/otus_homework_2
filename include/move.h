#ifndef __MOVE_H__
#define __MOVE_H__

#include <icommand.h>
#include <imovingobject.h>
#include <memory>

class Move: public ICommand
{
    std::shared_ptr<IMovingObject> _object;
    public:
    Move(std::shared_ptr<IMovingObject> moveObject)
    {
        _object = moveObject;
    };
    void Execute() const;
};

#endif