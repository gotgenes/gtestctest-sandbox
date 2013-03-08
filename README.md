# GoogleTest and GoogleMock test project

This is a test project for trying out [GoogleTest](https://code.google.com/p/googletest/) and [GoogleMock](https://code.google.com/p/googlemock/).

The recommended way to build this project is to do

```
mkdir build
cd build
cmake ..
make
ctest
```

The sandboxed project has three tests spread out over 2 test cases.
2 of the tests are expected to pass, 1 test is expected to fail.
To see the more detailed output from the test runner use:

```
ctest --verbose
```
