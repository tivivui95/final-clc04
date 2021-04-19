#include "Header.h"

void createNewYear() {

}

void AddNewSubject()
{

}

void DeleteSubject(Node*& head)
{
    string x;
        cout << "Enter an int: ";
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
            createNewYear();
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