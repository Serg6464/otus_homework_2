#ifndef __FUELEXCEPTION_H__
#define __FUELEXCEPTION_H__

#include <memory>
#include <iexception.h>

class FuelException: public IException
{
public:
    virtual ~FuelException() = default;

    FuelException()
    {
    }
    std::string what()
    {
        return std::string("fuel error");
    };
}
;

#endif