#ifndef __VECTOR_H__
#define __VECTOR_H__

class vector
{
    int x = 0;
    int y = 0;
public:
    vector(int x_val, int y_val);

    friend vector operator + (const vector &v1, const vector &v2);
}v

#endif