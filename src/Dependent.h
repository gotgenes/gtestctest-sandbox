#ifndef __DEPENDENT_H__
#define __DEPENDENT_H__

#include "Service.h"

class Dependent
{
public:
    int useService(Service &s) { return s.returnOne();}
};

#endif
