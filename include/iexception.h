#ifndef __IEXCEPTION_H__
#define __IEXCEPTION_H__

#include <string>

class IException
{
    public:
    virtual ~IException() = default;

    virtual std::string what() = 0;
};


#endif