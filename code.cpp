#include <chrono>
#include <iostream>
#include <limits>
#include <random>

using namespace std::chrono;

int main() {
    // to increment size of allocation
    size_t i = 1;
    int val;

    // to measure time difference
    time_point<steady_clock> start{0ms}, end{0ms};
    duration<int, std::micro> diff_heap;
    duration<int, std::micro> diff_stack;

    // to get random fills in the arrays
    std::uniform_int_distribution<int> distribution(
        0, std::numeric_limits<int>::max());
    std::mt19937 generator(system_clock::now().time_since_epoch().count());

    while (diff_heap.count() >= diff_stack.count()) {
        int* _stack = (int*)alloca(i * 8);
        int* _heap  = (int*)malloc(i * 8);

        // 1024 / 4 = 256, as sizeof(int) = 4
        for (size_t j = 0; j < 256 * i; ++j)
            _heap[i] = _stack[i] = distribution(generator);

        val = 0;

        start = steady_clock::now();
        for (size_t j = 0; j < 256 * i; ++j) val += _heap[i];
        end       = steady_clock::now();
        diff_heap = duration_cast<microseconds>(end - start);

        val   = 0;
        start = steady_clock::now();
        for (size_t j = 0; j < 256 * i; ++j) val += _stack[i];
        end        = steady_clock::now();
        diff_stack = duration_cast<microseconds>(end - start);

    	std::cout << i * 8 << " bytes" << std::endl;
    	std::cout << "stack: " << diff_stack.count() << std::endl;
    	std::cout << "heap: " << diff_heap.count() << std::endl;

        // heap one needs to be freed
        free(_heap);
        ++i;
    }

    return 0;
}
