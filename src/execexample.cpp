#include <iostream>

#include "Dependent.h"
#include "Service.h"

int main()
{
    using namespace std;
    Service s;
    Dependent d;
    int result = d.useService(s);
    cout << "Got " << result << endl;
}

