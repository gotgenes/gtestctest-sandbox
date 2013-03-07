#ifndef __MOCK_SERVICE__
#define __MOCK_SERVICE__

//#include "gmock/gmock.h"
#include "Service.h"

/*
Mock Service class inherits from service
*/
class MockService : Service
{
   // MOCK_METHOD0(returnOne, void()); //method with 0 parameter and returns nothing
   // MOCK_METHOD1(returnGiven, int(int x))  //method with 1 parameter (int) that returns an int
};
#endif
