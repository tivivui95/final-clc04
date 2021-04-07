#include "Header.h"

void studentDashboard()
{
	int choice;
	cout << "1.Enroll\n";
	cout << "2.Manage Class\n ";
	cout << "3.Manage course\n";
	cout << "4.Manage score\n";
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
		cout << head->num << ". " << head->name << "\n";
		head = head->next;
	}
}

