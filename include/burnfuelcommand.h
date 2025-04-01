#ifndef __BURNFUELCOMMAND_H__
#define __BURNFUELCOMMAND_H__

#include <icommand.h>
#include <ifuelobject.h>
#include <memory>

//команда сжигающая топливо
class BurnFuelCommand: public ICommand
{
    std::shared_ptr<IFuelObject> _object;
    public:
    BurnFuelCommand(std::shared_ptr<IFuelObject> fuelObject)
    {
        _object = fuelObject;
    };
    void Execute() const;
};

#endif