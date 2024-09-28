#include "cat.h"

Cat::Cat(const std::string &name) : Pet(name, "Cat") { }

std::string Cat::speak()
{
    return "meow";
}
