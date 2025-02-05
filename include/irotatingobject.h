#ifndef __IROTATINGOBJECT_H__
#define __IROTATINGOBJECT_H__

#include <direction.h>

class IRotatingObject
{
    public:
    ~IRotatingObject() = default;

    virtual direction get_direction() = 0;
    virtual void set_direction(direction new_direction) = 0;
    virtual direction get_rotation_speed() = 0;
};

#endif