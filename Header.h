#ifndef HEADER_H
#define HEADER_H
// #include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <cstdlib>
#include <stdlib.h>
#include <windows.h>
#include <cstring>
#include <vector>
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

struct Lecture
{
    char* name;
	char* academy;
	int gender;
};

struct Year
{
	char* yearsData;
	char* semestersData;
	char* coursesData;
	char* className;
	Year* pNext;
};

struct Time
{
	int hours;
	int mins;
};

struct Date
{
  int day;
  int month;
  int year;
};
struct Schedule
{
	int no;
	char* courseID;
	char* courseName;
	char* Class;
	char* dayofweek;
	lecture* lec;
	Date Sdate;
	Date Edate;
	Time Stime;
	Time Etime;

};

struct Course
{
    string courseID, courseN, teacherName, dayPerform;
    int daysOfWeek;
    // struct Student.FirstName;
    // struct Student.LastName;
};
struct Student
{
    string FullName, StudentID, Gender, DoB;
    int No, SocialID, SchoolYear;
};

struct Class
{
    string name;
    Student student;
};


struct LoginStudent
{
    string FullName, Username, UserId;
    Student* Detail;
};


// Login.cpp
bool LoginMain(LoginM* &dat);

// Create subject for admin.cpp
void CreateSchoolYear(Node*& pHead);
void AddStudent(Node* &pHead);
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

// Student Dashboard
void viewList(fstream &lop);
void removecourse(Node*& subject);
void viewListOfClass(fstream &lop);
void viewListofStudentinClass(fstream &student);
Node* enroll(Node* head, fstream &lop, fstream &student, Student info);
void studentDashboard(Node* head, fstream &student,fstream &lop, Student info, int choice);

// staffDashBoard.cpp
void CreateSubject(Node*& head);
void maindashboard(int input, Node*& head);
void AddNewSubject(Node*&head);
void DeleteSubject(Node*&head);

bool year_is_exist(Year* &pHead, int& n, char* year);
void createNewYear(Year* &pHead, int n, char* year);
void deleteYear(Year*& pHead);

bool semester_is_exist(Year* &pHead, int &n, char* year, char* semester);
void createNewSemester(Year* &pHead, int &n, char* year, char* semester);
void deleteSemester(Year* &pHead1);

bool course_is_exist(Year*& pHead, int& n, char* year, char* semester, char* course);
void createNewCourse(Year* pHead, int &n, char* year, char* semester, char* course);
void deleteCourse(Year* &pHead2);

void createYSC();

void Display(Node*& head, ofstream& Subject_file);

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
// double GPA(int score_earn, int total credit);
bool Sort(double average_score, double GPA);
// double Average score(int score);
#endif
