#ifndef HEADER_H
#define HEADER_H
// #include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include <sstream>
#include <Windows.h>
#include <cstdlib>
#include <stdlib.h>
#include <windows.h>
using namespace std;

#define MaxStudent 50;
// Setting accent, Don't change anything in this class, it's for Vietnamese character

class Person
{
public:
    Person() { ; };
    Person(string name, int No, bool gender, int studentID, int socialID, string DoB);
    ~Person() { ; };
    void operator =(Person& p);
    string get_name() const { return name; }
    int get_age() const { return age; }
    bool get_sex() const { return gender; }
    int get_studentID() const { return studentID; }
    int get_socialID() const { return socialID; }
    string get_DoB() const { return DoB; }

    void ShowInfo()
    {
        cout << "Name: " << name.c_str();
        cout << "No: " << No;
        cout << "Gender: " << ((gender == 1) ? "Male" : "Female");
        cout << "Student ID: " << studentID;
        cout << "Social ID: " << socialID;
        cout << "Date of Birth: " << DoB.c_str();

    }
private:
    string name;
    string DoB;
    int No;
    bool gender;
    int studentID, socialID;
};


class MBuf: public std::stringbuf {
public:
    int sync() {
        fputs( str().c_str(), stdout );
        str( "" );
        return 0;
    }
};
// Start here
struct Student
{
    string FullName, StudentID, Gender, DoB;
    int No, SocialID, SchoolYear;
};

struct LoginStudent
{
    string FullName, Username, UserId;
    Student* Detail;
};

struct Node
{
	int num;
	string data;
	Node* next;
};
// Login struct
struct LoginM
{
	string LoginId, id, type;
	bool check;
};
// Current Staff
struct Stafftime
{
    string courseName, courseId, day1, time1, day2, time2;
    Stafftime* Nextcourse;
};
struct Staff
{
    string FullName, Username, UserId;
    Stafftime* Allcourse;
};

struct Course
{
    string courseID, courseN, teacherName, dayPerform;
    int daysOfWeek;
    // struct Student.FirstName;
    // struct Student.LastName;
};

struct Class
{
    string name;
    struct Student;
};




// Login.cpp
bool LoginMain(LoginM* &dat);

// Create subject for admin.cpp
void CreateSubject(Node*& head);
void CreateSchoolYear(Node*& pHead);
void AddAndDisplayStudent(Node*& head);
void Display(Node*& head);
// void enroll(Node&* head);
void EditClassInfo(Node*& head2);
void Navigation(int& choice);
void Login(ifstream& f, string& k);

// NavBar.cpp
void DisplayNavStaff(Staff*&data);
void NavProcess(int input);
void DisplayNavStudent(LoginStudent* LStu);
void studentDbView(LoginM* data);
void staffDbView(LoginM* data);

// staffDashBoard.cpp
void maindashboard(int input);
void createNewYear();
void AddNewSubject(Node&head);
void DeleteSubject(Node&head);

// UI function in UI.cpp
void UITitle(string input);
void UILineLong();
void UILineShort();
void UIgrid_2_1_Long(string string1, string string2);
void UIgrid_2_1_Short(string string1, string string2);
void UIgrid_3_1_Long(string string1, string string2, string string3);
void UIgrid_3_1_Short(string string1, string string2, string string3);
void UIInput(string label);
void Loading();
int UICin(int& n);
void UIgrid_1_1_Long(string string);
void UIgrid_1_1_Short(string string);

//Edit class

#endif
