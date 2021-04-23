#include "Header.h"



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






