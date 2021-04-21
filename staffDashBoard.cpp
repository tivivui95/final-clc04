#include "Header.h"

void AddNewSubject(Node*&head)
{
    string name;
    Node* NewSubject = new Node;
    cout << "enter subject's name: ";
    getline(cin, name);
    int x;
    cout << "enter credits: ";
    cin >> x;
    NewSubject->data = name;
    NewSubject->num = x;
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
                Node* k = tmp->next;
                tmp->next = tmp->next->next;
                delete k;
            }
            else
            {
                tmp = tmp->next;
            }
        }
}

void maindashboard(int input, Node&head) {
    switch (input)
    {
    case 1:
        {
        CreateSchoolYear(pHead);
            break;
        }
    case 2:
        {
            AddNewSubject(head);
            break;
        }
    case 3:
        {
            DeleteSubject(head);
            break;
        }
    
    default:
        break;
    }
}