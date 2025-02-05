#ifndef __ROTATE_H__
#define __ROTATE_H__

#include <icommand.h>
#include <irotatingobject.h>
#include <memory>

class Rotate: public ICommand
{
    std::shared_ptr<IRotatingObject> _object;
    public:
    Rotate(std::shared_ptr<IRotatingObject> Object)
    {
        _object = Object;
    };
    void Execute() const;
};

#endif