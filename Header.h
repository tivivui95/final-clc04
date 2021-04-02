#ifndef HEADER_H
#define HEADER_H

#include<iostream>
#include<string>
using namespace std;

struct Node
{
    string FirstName, LastName, Student ID, Gender, DoB;
    int No, Social ID, SchoolYear;
	int num;
	Node* next;
};
void CreateSubject(Node*& head);
void Display(Node*& head);

#endif
