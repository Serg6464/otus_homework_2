#ifndef __IEXCEPTION_H__
#define __IEXCEPTION_H__

#include <string>

class IException
{
    std::string _what;
    public:
    ~IException() = default;
    IException(std::string what)
    {
        _what = what;
    };
    const char * what() const
    {
        return _what.c_str();
    };
};


#endif