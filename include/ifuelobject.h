#ifndef __IFUELOBJECT_H__
#define __IFUELOBJECT_H__

#include <fuel.h>

class IFuelObject
{
public:
    virtual ~IFuelObject() = default;

    virtual fuel getFuel() = 0;
    virtual void setFuel(fuel fuelvalue) = 0;

    virtual fuel getFuelConsumption() = 0;
};

#endif