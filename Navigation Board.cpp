#include"Header.h"


void Navigation(int& choice)
{
	cout << "MOODLE\n";
	cout << "1. Staff members\n";
	cout << "2. Students\n";
	cout << "0. EXIT\n";
	cout << "Choose your number: ";
	cin >> choice;
	while (choice > 2 || choice < 0)
	{
		cout << "Error! Enter again: ";
		cin >> choice;
	}

	switch (choice)
	{
	case 1:
	{
		cout << "STAFF LOGIN\n";
		string check;
	}
	break;

	case 2:
	{
		cout << "STUDENT LOGIN\n";
		string check;
		cout << "Enter student id: ";
		cin.ignore();
		getline(cin, check);
	}
	break;

	case 0:
	{
		cout << "Bye for hundreds times\n";
		return;
	}
	break;
	}

}

void Login(ifstream& f, string& k)
{
	f.open("Data.txt", ios::in);
	if (f.is_open())
		cout << "Ready to go.\n";
	else
	{
		cerr << "Error\n";
		return;
	}
}