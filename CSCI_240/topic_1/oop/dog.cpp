#include "dog.h"

Dog::Dog(const std::string &name) : Pet(name, "Dog") { }

std::string Dog::speak()
{
    return "woof";
}
