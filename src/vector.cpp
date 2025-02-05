#include <vector.h>

vector::vector(int x_val, int y_val)
    : x(x_val), y(y_val)
{
}

vector operator + (const vector &v1, const vector &v2)
{
    return vector(v1.x + v2.x, v1.y + v2.y);
}

int operator == (const vector &v1, const vector &v2)
{
    return (v1.x == v2.x) && (v1.y == v2.y);
}