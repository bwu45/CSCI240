#include "student.h"

Student::Student(const std::string &id, const std::string &firstName, char mi, const std::string &lastName)
    : id{id}, firstName{firstName}, mi{mi}, lastName{lastName} {}

std::string Student::getId()
{
    return id;
}

std::string Student::getFirstName()
{
    return firstName;
}

char Student::getMiddleInitial()
{
    return mi;
}

std::string Student::getLastName()
{
    return lastName;
}

bool Student::operator==(const Student &other)
{
    return id == other.id;
}

bool Student::operator!=(const Student &other)
{
    return !(*this == other);
}
