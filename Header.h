#ifndef HEADER_H
#define HEADER_H

#include<iostream>
#include<string>
using namespace std;

class Student
{
    string Name, Student ID;
    int No;

};

struct Node
{
	int num;
	string name;
	Node* next;
};
void Create(Node*& head);
void Display(Node*& head);

#endif
