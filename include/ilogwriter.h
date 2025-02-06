#ifndef __ILOGWRITER_H__
#define __ILOGWRITER_H__

class ILogWriter
{
    public:
    ILogWriter() = default;
    virtual void WriteToLog(const char *message) = 0;
};

#endif