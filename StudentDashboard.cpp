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
		case 3:
		{
			removecourse(head);
		}

	}
	case 2:
	case 3:
	case 4:
	}
		
}

Node* enroll(Node &*head, Node &*subject)
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
				subject = now;
			}
			now = now ->next;
		}
	} while (t != 0);
	return subject;
}

void viewList(Node *subject)
{
	if (subject == nullptr) cout << "You havent enrolled any courses yet. Enroll first and come back here\n";
	else
	{
		Node *cur = subject;
	    cout << "The courses that you have alreay enrolled:\n ";
	    while (cur != nullptr)
	    {
		    cout << cur->num << ". " << cur->data << " \n";
	       	cur = cur->next;
	    }
	
	}
		
}
void removecourse(Node *subject)
{
	if (subject == nullptr) cout <<"There is no course to remove\n";
	else
	{
		Node* temp = subject;
		
	}
	
	
}