#ifndef __IMOVINGOBJECT_H__
#define __IMOVINGOBJECT_H__

#include <vector.h>

class IMovingObject
{
    public:
    ~IMovingObject() = default;

    virtual vector get_location() = 0;
    virtual void set_location(vector newloc) = 0;
    virtual vector get_velocity() = 0;
};

#endif