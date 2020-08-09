# Very Large Arrays on Stack

This code runs and gives the limit of size of array/memory block you can allocate on your computer's stack before reading data from it becomes slower than that of same size on heap. Simply run
```
make
```
in the project directory.

Requires C++17 or newer. Makefile uses g++. Don't enable optimizations as then the compiler will simply allocate once on stack/heap and there would be no actual comparison as it will keep on running till segfault.

Note that answer will vary each time you run, as it depends on your available system resources.

An interesting point to note is that g++ consistently outperforms reading from stack than clang.
