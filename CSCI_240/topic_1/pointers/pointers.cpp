#include <iostream>

void printArray(const int *, size_t);

int main(int argc, char const *argv[])
{
    // int a{55};
    // int *ptr{&a};
    int *a;

    // std::cout << ptr << std::endl << &a << std::endl << *ptr << std::endl;

    int array[]{1, 2, 3, 4, 5};
    int *arrayPtr{array};

    // std::cout << arrayPtr[1] << std::endl;
    // std::cout << *(array + 1) << std::endl;

    printArray(array, 5);
    printArray(arrayPtr, 5);

    return 0;
}

void printArray(const int *a, size_t count)
{
    std::cout << "[ ";

    // for (size_t i = 0; i < count; i++)
    //     std::cout << a[i] << std::endl;

    size_t i{};

    while (i++ < count)
        std::cout << *(a++) << " ";

    std::cout << "]\n";
}