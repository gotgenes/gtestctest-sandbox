#ifndef __MOCK_SERVICE__
#define __MOCK_SERVICE__

#include "gmock/gmock.h"
#include "Service.h"

/*
Mock Service class inherits from service
*/
class MockService : public  Service
{
public:
   MOCK_METHOD0(returnOne, int()); //method with 0 parameter and returns an int
};
#endif
