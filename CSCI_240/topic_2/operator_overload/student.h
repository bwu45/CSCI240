#include <string>

#ifndef STUDENT_H
#define STUDENT_H

class Student
{
public:
    Student(const std::string &, const std::string &, char, const std::string &);
    // nothing heap bound no need for destructor

    std::string getId();
    std::string getFirstName();
    char getMiddleInitial();
    std::string getLastName();

    bool operator==(const Student &);
    bool operator!=(const Student &);

private:
    std::string id;
    std::string firstName;
    char mi;
    std::string lastName;
};

#endif /* STUDENT_H */