#ifndef HEADER_H
#define HEADER_H

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
// Login
struct LoginM
{
	string LoginId, id, type;
	bool check;
};
// Login.cpp
void LoginMain(string& loginId, string& Id, string& type, bool& check);

void CreateSubject(Node*& head);
void CreateSchoolYear(Node*& pHead);
void AddAndDisplayStudent(Node*& head);
void Display(Node*& head);
// void enroll(Node&* head);
void EditClassInfo(Node*& head2);
void Navigation(int& choice);
void Login(ifstream& f, string& k);

// UI function
void UITitle(string input);
void UILineLong();
void UILineShort();
void UIgrid_2_1_Long(string string1, string string2);
void UIgrid_2_1_Short(string string1, string string2);
void UIInput(string label);
void Loading();
#endif
