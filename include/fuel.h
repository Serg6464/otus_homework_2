#ifndef __FUEL_H__
#define __FUEL_H__

class fuel
{
    unsigned int m_nvalue;

public:
    fuel(unsigned int fuelvalue)
    {
        m_nvalue = fuelvalue;
    }

    friend int operator == (const fuel &value1, const fuel &value2)
    {
    return value1.m_nvalue == value2.m_nvalue;
    }
    friend int operator != (const fuel &value1, const fuel &value2)
    {
        return !(value1 == value2);
    }
    friend int operator < (const fuel &value1, const fuel &value2)
    {
        return value1.m_nvalue < value2.m_nvalue;
    }
    
    friend fuel operator - (const fuel &value1, const fuel &value2)
    {
        if( !(value1 < value2) )
        {
            return fuel(value1.m_nvalue-value2.m_nvalue);
        }
        return fuel(0);
    }
};

#endif