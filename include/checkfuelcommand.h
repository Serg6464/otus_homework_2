#ifndef __CHECKFUELCOMMAND_H__
#define __CHECKFUELCOMMAND_H__

#include <icommand.h>
#include <ifuelobject.h>
#include <memory>

//команда проверяющая достаточность топлива
class CheckFuelCommand: public ICommand
{
    std::shared_ptr<IFuelObject> _object;
    public:
    CheckFuelCommand(std::shared_ptr<IFuelObject> fuelObject)
    {
        _object = fuelObject;
    };
    void Execute() const;
};

#endif