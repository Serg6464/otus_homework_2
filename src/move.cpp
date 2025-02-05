#include <move.h>

void Move::Execute() const
{
    _object->set_location( _object->get_location() + _object->get_velocity() );
}