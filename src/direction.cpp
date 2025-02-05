#include <direction.h>   
   
    int _angle0_359 = 0;

direction::direction(int initial_direction_angle)
{
    _angle0_359 = initial_direction_angle % 360;
    if( _angle0_359 < 0 ) _angle0_359 += 360;
}

direction operator + (const direction &d1, const direction &d2)
{
    return direction( d1._angle0_359+d2._angle0_359);
}

int operator == (const direction &d1, const direction &d2)
{
    return d1._angle0_359 == d2._angle0_359;
}