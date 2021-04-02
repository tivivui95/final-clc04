#ifndef HEADER_H
#define HEADER_H

#include<iostream>
#include<string>
using namespace std;

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
void CreateSubject(Node*& head);
void Display(Node*& head);

#endif
