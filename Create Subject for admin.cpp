#include "Header.h"

void CreateSubject(Node*& head)
{
	int n, k;
	cout << "Enter the number subject that you want to create: ";
	cin >> n;

	string t;

	for (int i = 0; i < n; i++)
	{
		cout << "#" << i + 1 << endl;
		cout << "Subject Name: ";
		cin.ignore();
		getline(cin, t);
		cout << "Credits: ";
		cin >> k;

		Node* subject = new Node;
		subject->next = nullptr;
		subject->name = t;
		subject->num = k;

		if (head == nullptr)
			head = subject;
		else
		{
			Node* p = head;
			while (p->next != nullptr)
				p = p->next;
			p->next = subject;
		}
	}
	cout << endl;
}

void Display(Node*& head)
{
	Node* trace = head;
	cout << "SUBJECT LIST\n";
	cout << "NAMES" << "\t" << "CREDITS\n";
	cout << "--------------------------------------\n";
	while (trace)
	{
		cout << trace->name << "\t" << trace->num << endl;
		trace = trace->next;
	}
}