#ifndef __CONSOLELOGWRITER_H__
#define __CONSOLELOGWRITER_H__

#include <ilogwriter.h>

//выводит ЛОГ в стандартную консоль
class ConsleLogWriter: public ILogWriter
{
     public:
    ConsleLogWriter() = default;
    virtual void WriteToLog(const char *message);
};

#endif