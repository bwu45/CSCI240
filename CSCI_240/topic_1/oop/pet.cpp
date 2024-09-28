#include "pet.h"

//created, initialized, and assigned value 1 step
Pet::Pet(const std::string &name, const std::string &species) : name{name}, species{species} { }

//created and initialized, then assigned value 2 step
// Pet::Pet(const std::string &name, const std::string &species) 
// {
//     this->name = name;
//     this->species = species;
// }

std::string Pet::getName()
{
    return name;
}

std::string Pet::getSpecies()
{
    return species;
}

//no longer needed because pure virtual 
// std::string Pet::speak()
// {
//     return "N/A";
// }
