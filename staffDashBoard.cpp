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
        subject->data = t;
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

void AddNewSubject(Node*& head)
{
    string name;
    Node* NewSubject = new Node;
    cout << "enter subject's name: ";
    cin.ignore();
    getline(cin, name);
    int x;
    cout << "enter credits: ";
    cin >> x;
    NewSubject->data = name;
    NewSubject->num = x;
    NewSubject->next = nullptr;
    Node* ptr;
    if (head == nullptr)
        head = NewSubject;
    else
    {
        ptr = head;

        while (ptr->next != nullptr)
            ptr = ptr->next;

        ptr->next = NewSubject;
    }
}

void DeleteSubject(Node*& head)
{
    string x;
    cout << "Enter name subject that u want to delete: ";
    cin.ignore();
    getline(cin, x);

    Node* tmp = head;

    while (head->data == x)
    {
        Node* c = head;
        head = head->next;
        delete c;
    }
    while (tmp->next != nullptr)
    {
        if (tmp->next->data == x)
        {
            Node* c = tmp->next;
            tmp->next = tmp->next->next;
            delete c;
        }
        else
        {
            tmp = tmp->next;
        }
    }
}

void maindashboard(int input, Node*& head) 
{
    switch (input)
    {
    case 1:
    {
        AddNewSubject(head);
        break;
    }
    case 2:
    {
        DeleteSubject(head);
        break;
    }

    default:
        break;
    }
}

void Display(Node*& head, ofstream& Subject_file)
{
    Node* trace = head;

    while (trace)
    {
        Subject_file << trace->data << endl;
        Subject_file << trace->num << endl;
        trace = trace->next;
    }
}