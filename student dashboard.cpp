#include "Header.h"

void studentDashboard()
{
	int choice;
	cout << "1.Enroll" << endl;
	cout << "2.Manage Class " << endl;
	cout << "3.Manage course" << endl;
	cout << "4.Manage score" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	}
		
}

void enroll(Node &*head)
{
	cout << " List of courses" << endl;
	while (head != nullptr)
	{
		cout << head->num << ". " << head->name;
		head = head->next;
	}
}
