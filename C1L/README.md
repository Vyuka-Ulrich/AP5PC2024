### How to run on windows:
```bash
$ mkdir build
$ cd build
$ cmake -G "MinGW Makefiles" ..
$ cmake --build .
```

### How to run on unix:
```bash
$ mkdir build
$ cd build
$ cmake -G "Unix Makefiles" ..
$ cmake --build .
```

###  how to run tests:
CMakeLists.txt
```
...
add_subdirectory(test)
...
```

test/CMakeLists.txt
```
...
add_executable(
  add_test <--- nazev executable
  adder_test.cpp
)
...
```

```bash
$ cd build
$ ./test/add_test(.exe)
```


### Libray:

Function to add two integers
```c
int add(int a, int b);
```
