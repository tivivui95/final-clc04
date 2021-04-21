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

template <typename T>
class NodeData
{
public:
    NodeData() : next_(NULL) { ; }
    void         set_data(T val) { data_ = val; }
    T            get_data() const { return data_; }
    void         set_next(NodeData<T>* next) { next_ = next; }
    NodeData<T>* get_next() const { return next_; };
private:
    T            data_;
    NodeData<T>* next_;



class Person
{
public:
    Person() { ; };
    Person(string name, int No, bool gender, int studentID, int socialID, string DoB);
    ~Person() { ; };
    void operator =(Person& p);
    string get_name() const { return name_; }
    int get_No() const { return No_; }
    bool get_gender() const { return gender_; }
    int get_studentID() const { return studentID_; }
    int get_socialID() const { return socialID_; }
    string get_DoB() const { return DoB_; }

    void ShowInfo()
    {
        cout << "Name: " << name_.c_str();
        cout << "No: " << No_;
        cout << "Gender: " << ((gender_ == 1) ? "Male" : "Female");
        cout << "Student ID: " << studentID_;
        cout << "Social ID: " << socialID_;
        cout << "Date of Birth: " << DoB_.c_str();

    }
private:
    string name_;
    string DoB_;
    int No_;
    bool gender_;
    int studentID, socialID_;
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
void AddNewSubject(Node*&head);
void DeleteSubject(Node*&head);
void CreateSchoolYear(Node*& pHead);
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

//Score calculation


#endif
