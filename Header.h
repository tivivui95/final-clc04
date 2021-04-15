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
    string FirstName, LastName, StudentID, Gender, DoB;
    int No, SocialID, SchoolYear;
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
    struct Student.FirstName;
    struct Student.LastName;
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
void DisplayNav(Staff*&data);
void NavProcess(int input);

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
