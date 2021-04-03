#ifndef HEADER_H
#define HEADER_H

#include<iostream>
#include<string>
#include<fstream>
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
void enroll(Node&* head);
void Navigation(int& choice);
void Login(ifstream& f, string& k);

#endif
