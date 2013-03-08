#ifndef __SERVICE_H__
#define __SERVICE_H__

class Service{

public:
    
    virtual int returnOne()
    {
        return 1;
    }

    virtual int returnGiven(int x)
    {
        return x;
    }

};

#endif
