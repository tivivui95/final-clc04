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

void CreateSchoolYear(Node* &pHead)
{
    int n;
    cout << "Enter the schoolyear that you want to create: "; cin >> n;
    for (int i = 0; i <= 6; i++)
    {
        Node* schoolyear = new Node();
        schoolyear->next = nullptr;
        schoolyear->num = n;
    }

}

void AddAndDisplayStudent(Node* &head)
{
    Student s;
    cout << "Enter the information of the student: " << endl;
    cout << "Enter the first name: "; cin >> s.FirstName;
    cout << "Enter the last name: "; cin >> s.LastName;
    cout << "Enter the gender: "; cin >> s.Gender;
    cout << "Enter the data of birth: "; cin >> s.DoB;
    cout << "Enter the student ID: "; cin >> s.StudentID;
    cout << "Enter the social ID: "; cin >> s.SocialID;

    cout << "List of Students: " << endl;
    cout << "FIRST NAME: " << s.FirstName << endl;
    cout << "LAST NAME: " << s.LastName << endl;
    cout << "GENDER: " << s.Gender << endl;
    cout << "DATE OF BIRTH: " << s.DoB << endl;
    cout << "STUDENT ID: " << s.StudentID << endl;
    cout << "SOCIAL ID: " << s.SocialID << endl;

}









