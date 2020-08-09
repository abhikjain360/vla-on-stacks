app:
	rm -rf code && clang++ code.cpp -O3 -Wall -Wpedantic -std=c++17 -o code && ./code
debug:
	rm -rf code && clang++ code.cpp -g -Wall -Wpedantic -std=c++17 -o code && gdb ./code
