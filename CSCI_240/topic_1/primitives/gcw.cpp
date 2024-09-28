#include <iostream>
#define WINDOWS std::cout << "wtf??" << std::endl

int main(int argc, char const *argv[])
{
    std::cout << argc << std::endl;
#ifdef WINDOWS
    WINDOWS;
#endif
    return 0;
}