#include <string>

#ifndef PET_H
#define PET_H

class Pet
{
public:
    Pet(const std::string &, const std::string &); // objects should always be passed by reference

    std::string getName();
    std::string getSpecies();
    virtual std::string speak() = 0; // pure virtual function with = 0

private:
    std::string name;
    std::string species;
};

#endif /* PET_H */