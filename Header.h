#ifndef HEADER_H
#define HEADER_H

#include<iostream>
#include<string>
using namespace std;

struct Node
{
	int num;
	string name;
	Node* next;
};
void Create(Node*& head);
void Display(Node*& head);

#endif
