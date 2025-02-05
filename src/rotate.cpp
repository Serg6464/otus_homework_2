
#include <rotate.h>

#include <move.h>

void Rotate::Execute() const
{
    _object->set_direction( _object->get_direction() + _object->get_rotation_speed() );
}