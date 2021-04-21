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

template <typename N>
class NodeData
{
public:
    NodeData(): next(NULL) { ; }
    void setdata(N val) {data = val;}
    N getdata() const {return data;}
    void setnext(NodeData<N>* next) {pnext = next}
    NodeData<N>* getnext() const {return pnext;}
private:
    N data;
    NodeData<N>* pnext;
};

class LinkedList


class MBuf: public std::stringbuf {
public:
    int sync() {
        fputs( str().c_str(), stdout );
        str( "" );
        return 0;
    }
};
// Start here

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
    struct Student student;
};
struct Student
{
    string FullName, StudentID, Gender, DoB;
    int No, SocialID, SchoolYear;
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
