#include "Header.h"

void studentDashboard(Node* head, fstream &student,fstream &lop, Student info, int choice)
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
		{
		case 1:
		{
			enroll(head,lop, student, info);
			break;
		}
		case 2:
		{
			viewList(lop);
			break;
		}
		case 3:
		{
			removecourse(head);
			break;
		}
		}
		break;
	}
	case 2:
	{
		int b;
		cout << "1.View list of class\n";
		cout << "2.View list of student in class\n";
		cin >> b;
		switch (b)
		{
		case 1:
		{
			viewListOfClass(lop);
			break;
		}
		case 2:
		{
			viewListofStudentinClass(student);
			break;
		}
		}
	}
	case 3:
	{

	}
	}

}

Node* enroll(Node* head, fstream &lop, fstream &student, Student info)
{
	Node* cur = head;
	cout << " List of courses\n";
	while (cur != nullptr)
	{
		cout << cur->num << ". " << cur->data << "\n";
		cur = cur->next;
	}
	int t;
	do
	{
		Node* now = head;
		cout << "Which subject do you want to enroll?(Write the number,0 to stop): \n";
		cin >> t;
		while (now != nullptr)
		{
			if (now->num == t)
			{
				cout << "You successfully enroll the subject: " << now->data << endl;
				student << info.FullName << endl;
				lop << now->num << "," << now->data << endl;
			}
			now = now->next;
		}
	} while (t != 0);

}

void viewList(fstream &lop)
{
	string data;
	while (!lop.eof())
	{
		getline(lop, data, ',');
		cout << data << endl;
	}
}

void removecourse(Node*& subject)
{
	string x;
	cout << "Enter an int: ";
	cin.ignore();
	getline(cin, x);
	Node* tmp = subject;
	if (subject->data == x)
	{
		Node* c = subject;
		subject = subject->next;
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

void viewListOfClass(fstream &lop)
{
	string data;
	while (!lop.eof())
	{
		getline(lop,data,',');
		cout << data << endl;
	}
}

void viewListofStudentinClass(fstream &student)
{
	string line;
	while (!student.eof())
	{
		getline(student, line);
		cout << line << endl;
	}
}