#include "Header.h"

Person::Person(string name, string DoB, int No, int studentID, int socialID, bool gender)
{
    name_ = name;
    No_ = No;
    gender_ = gender;
    DoB_ = DoB;
    studentID_ = studentID;
    socialID_ - socialID;
}

void Person::operator = (Person& p)
{
    this->name_ = p.name_;
    this->No_ = p.no_;
    this->gender_ = p.gender_;
    this->DoB_ = p.DoB_;
    this->studentID_ = p.studentID_;
    this->socialID_ = p.socialID_;
}
