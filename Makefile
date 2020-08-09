app:
	rm -rf code && g++ code.cpp -g -Wall -Wpedantic -std=c++17 -o code && ./code
debug:
	rm -rf code && g++ code.cpp -g -Wall -Wpedantic -std=c++17 -o code && gdb ./code
