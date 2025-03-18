#ifndef __ILOGWRITER_H__
#define __ILOGWRITER_H__

#include <string>
#include <ilogwriter.h>

class ILogWriter
{
    public:
    ~ILogWriter() = default;
    virtual void Write(std::string message) = 0;
};

#endif