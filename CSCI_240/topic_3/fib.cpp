#include <iostream>

size_t fib(size_t);
void printArray(int array[], size_t size);
size_t fact(size_t n);
int binSearch(int[], int, int, int);

int main(int argc, char const *argv[])
{
    int array[]{1, 4, 5, 29, 33, 55, 80}; // 1.844674407x10^19 = 2^64 = log2(n) 

    std::cout << binSearch(array, 0, 6, 0) << std::endl;
    std::cout << binSearch(array, 0, 6, 1) << std::endl;
    std::cout << binSearch(array, 0, 6, 80) << std::endl;
    std::cout << binSearch(array, 0, 6, 5) << std::endl;
    std::cout << binSearch(array, 0, 6, 100) << std::endl;

    // std::cout << fib(0) << std::endl;
    // std::cout << fib(5) << std::endl;
    // std::cout << fib(10) << std::endl;
    // std::cout << fib(50) << std::endl;

    // std::cout << fact(0) << std::endl;
    // std::cout << fact(1) << std::endl;
    // std::cout << fact(10) << std::endl;

    return 0;
}

int binSearch(int array[], int start, int end, int term)
{
    int mid{(start + end) >> 1};

    if (start > end) // first base case
        return -1;

    if (term == array[mid]) // second base case
        return mid;

    if (term < array[mid]) // lower half
        return binSearch(array, start, mid - 1, term);

    return binSearch(array, mid + 1, end, term); // upper half
}

// O(n)
size_t fib(size_t n)
{
    // first 2 values of fibonacci 0, 1
    size_t t{0}; // trailing
    size_t g{1}; // guiding
    size_t tmp{};

    for (size_t i{}; i < n; ++i)
    {
        tmp = t;
        t = g;
        g = tmp + g;
    }

    return t;
}

// size_t fib(size_t n)
// {
//     if (n <= 1)
//         return n; // base case

//     return fib(n - 1) + fib(n - 2); // recursion case
// }

void printArray(int array[], size_t size)
{
    for (size_t i = 0; i < size; ++i)
        std::cout << array[i] << " ";
}

size_t fact(size_t n)
{
    if (n <= 1)
        return 1; // base case, constant time case

    return n * fact(n - 1);
}
