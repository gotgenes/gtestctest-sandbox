# GoogleTest and GoogleMock test project

This is a test project for trying out
[GoogleTest](https://code.google.com/p/googletest/) and
[GoogleMock](https://code.google.com/p/googlemock/) and integrating them
with CMake and CTest.

The recommended way to build this project is to do

```
mkdir build
cd build
cmake ..
make
ctest
```

The sandboxed project has three unit tests contained in two test cases,
and two integration tests as scripts. Two of the unit tests are expected
to pass, one test is expected to fail, and one of the integration tests
is expected to pass and also one to fail. To see the more detailed
output from the test runner use:

```
ctest --verbose
```

