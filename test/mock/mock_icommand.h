#ifndef __MOCK_ICOMMAND_H__
#define __MOCK_ICOMMAND_H__

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <icommand.h>

class CMockCommand:public ICommand
{
    public:
     MOCK_METHOD( void, Execute, (), (const));
};

#endif