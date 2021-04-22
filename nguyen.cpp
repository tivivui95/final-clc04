#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct Node
{
    int num;
    char data;
    Node* next;
};




string input()
{
    string t;
    cout<<"Enter name: ";
    getline(cin, t);
    return t;
}

Node* addNewNode(char data)
{
    Node* neww = new Node();
    neww->data = data;
    neww->next = nullptr;
    return neww;
}

Node* s2ll(string text, Node* pHead)
{
    pHead = addNewNode(text[0]);
    Node* pCur = pHead;
    for (int i = 1; i < text.size(); i++)
    {
        pCur->next = addNewNode(text[i]);
        pCur = pCur->next;
    }
    return pHead;

}

void display(Node* &pHead)
{
    Node* pCur = pHead;
    while (pCur)
    {
        cout << pCur->data;
        pCur = pCur->next;
    }
}

int main()
{
    /*string text = input();

    Node* pHead = nullptr;
    pHead = s2ll(text, pHead);

    cout << "Linked list: ";
    display(pHead);*/

    ofstream f;
    f.open("E:/Data_Bin/20127261_KTLT/Final_TH/final-clc04/20/classData/20clc01/nguyen.txt");

    for (int i = 0; i < 20; i++)
    {
        f << i << "," << i*i << endl;
    }
    return 0;
}
