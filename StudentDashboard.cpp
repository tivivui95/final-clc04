#include "Header.h"

void studentDashboard(Node *head,Node*subject,int choice)
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
			enroll(head,subject);
			break;
		}
		case 2:
		{
			viewList(head,subject);
			break;
		}
		case 3:
		{
			removecourse(subject);
			break;
		}

	}
	}
		
}

Node* enroll(Node *head, Node *subject)
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

void viewList(Node *head,Node *subject)
{
	if (subject == nullptr) 
	{
		cout <<"You should enroll first\n";
		enroll(head,subject);
	}
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

void removecourse(Node*& head)
{
    string x;
    cout << "Enter an int: ";
    cin.ignore();
    getline(cin, x);
    Node* tmp = head;
    if (head->data == x)
    {
        Node* c = head;
        head = head->next;
        delete c;
    }
    while (tmp->next != nullptr)
    {
    if (tmp->next->data == x)
        {
            Node* k = tmp->next;
            tmp->next = tmp->next->next;
            delete k;
        }
    else tmp = tmp->next;
    }
}