#include "Header.h"

void studentDashboard(Node *head,int choice)
{
	cout << "1.Enroll\n";
	cout << "2.Manage Class\n ";
	cout << "3.Manage course\n";
	cout << "4.Manage score\n";
	switch (choice)
	{
	case 1:
	{
		int a;
		cout << "1. Enroll course\n";
		cout << "2. View list of enroll course\n";
		cout << "3. Remove course\n";
		cin >> a;
		switch (a)
		case 1:
		{
			enroll(head);
			break;
		}
		case 2:
		{
			viewList(head);
		}

	}
	case 2:
	{}
	case 3:
	case 4:
	}
		
}

void enroll(Node &*head)
{
	Node *cur=head;
	cout << " List of courses\n";
	while (cur != nullptr)
	{
		cout << cur->num << ". " << cur->data << "\n";
		cur = cur->next;
	}
	int t;
	do 
	{
		Node *now = head;
		cout <<"Which subject do you want to enroll?(Write the number,0 to stop): \n";
		cin >> t;
		while (now != nullptr)
		{
			if (now->num == t)
			{
				cout << "You successfully enroll the subject: " << now->data << endl;
			}
			now = now ->next;
		}

	} while (t != 0);
}

void viewList(Node *head)
{
	
}
