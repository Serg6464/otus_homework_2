#include <burnfuelcommand.h>

void BurnFuelCommand::Execute() const
{
    _object->setFuel( _object->getFuel() - _object->getFuelConsumption());
}