#ifndef __ICOMMAND_H__
#define __ICOMMAND_H__

class ICommand
{
    public:
    virtual void Execute() const = 0; 
};


#endif