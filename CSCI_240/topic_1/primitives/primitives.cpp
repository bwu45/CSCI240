#include <iostream>

int global{100};

int main(int argc, char const *argv[])
{
    // integral data types, integer or whole number types
    unsigned int val{0xFFFFFFFF};
    unsigned int val2{20};
    short s{40};
    char c{'C'};
    bool b(0);
    long l{0b1010ll}; // 10
    long long ll{55};
    int global{26};
    size_t szt{1000};

    // real data type, floating point values
    float flt{3.14159f};
    double dbl{54.14f};
    long double ldbl{0.1 + 0.2};

    std::cout << static_cast<long long>(val) + val2 // casts then adds int
              << " " << sizeof static_cast<long long>(val) << std::endl;

    std::cout << static_cast<long long>(val + val2) << " " // int adds first then casts
              << sizeof static_cast<long long>(val) << std::endl;

    // std::cout << s << " " << sizeof s << std::endl;
    // std::cout << c << " " << sizeof c << std::endl;
    // if (val)
    //     std::cout << std::boolalpha << b << " " << sizeof b << std::endl;
    // std::cout << l << " " << sizeof l << std::endl;
    // std::cout << ll << " " << sizeof ll << std::endl;
    // std::cout << "address of global " << &global << std::endl
    //          << "address of val " << &val << std::endl;
    // {
    //     int global{52};
    //     std::cout << ::global << " " << global << std::endl;
    // }

    std::cout << flt << " " << sizeof flt << std::endl;
    std::cout << dbl << " " << sizeof dbl << std::endl;
    std::cout << ldbl << " " << sizeof ldbl << std::endl;

    return 0;
}