#ifndef __MOCK_LOGWRITER_H__
#define __MOCK_LOGWRITER_H__

#include <ilogwriter.h>

class CMockLogWriter: public ILogWriter
{
    public:
    MOCK_METHOD( void, Write, (std::string str));
};

#endif