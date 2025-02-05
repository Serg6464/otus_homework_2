#ifndef __DIRECTION_H__
#define __DIRECTION_H__

//неправление объекта - угол на плоскости в диапазоне 0-359 градусов
class direction
{
    int _angle0_359 = 0;
public:
    direction(int initial_direction_angle);

    friend direction operator + (const direction &d1, const direction &d2);
    friend int operator == (const direction &d1, const direction &d2);
};

#endif