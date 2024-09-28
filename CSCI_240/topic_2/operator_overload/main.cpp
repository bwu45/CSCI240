#include <iostream>

#include "student.h"

int main(int argc, char const *argv[])
{
    Student s1("A12347", "Dave", ' ', "Johnson");
    Student s2("A12345", "Dave", ' ', "Johnson");

    if (s1 == s2)
        std::cout << "they are the same student";
    else
        std::cout << "they are not equal\n";

    std::cout << s1.getId() + " " + s2.getId() << std::endl;
    return 0;
}
