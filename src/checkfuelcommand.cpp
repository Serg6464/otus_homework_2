#include <checkfuelcommand.h>
#include <fuelexception.h>

void CheckFuelCommand::Execute() const
{
    if( _object->getFuel() < _object->getFuelConsumption() )
    {
        throw FuelException();
    }
}