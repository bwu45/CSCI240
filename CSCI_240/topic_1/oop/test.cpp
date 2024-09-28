#include <iostream>
#include <vector>

#include "stack.h"
#include "dog.h"
#include "cat.h"
#include "pet.h"

int main(int argc, char const *argv[])
{
    // Dog d("Fido");
    // Cat c("Knuckles");

    // std::cout << d.getName() << " the " << d.getSpecies() << " says " << d.speak() << std::endl;
    // std::cout << c.getName() << " the " << c.getSpecies() << " says " << c.speak() << std::endl;

    // std::vector<Pet *> pets{ //similar to arraylists in Java
    //     new Dog{"Fido"}, new Cat{"Knuckles"},
    //     new Dog{"Clifford"}, new Cat{"Doug"}};

    // for (Pet *p : pets)
    //     std::cout << p->getName() << " the " << p->getSpecies() << " says " << p->speak() << std::endl;

    Stack<Pet *> pets;
    pets.push(new Dog{"Fido"});
    pets.push(new Dog{"Clifford"});
    pets.push(new Cat{"Knuckles"});
    pets.push(new Cat{"Doug"});

    while (!pets.empty())
    {
        Pet *p{pets.peek()};
        pets.pop();
        std::cout << p->getName() << " the " << p->getSpecies() << " says " << p->speak() << std::endl;
    }

    return 0;
}
