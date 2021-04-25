#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Node
{
    int num;
    char data;
    Node* next;
};

void readCSV(ifstream &f)
{
     ifstream f("E:\\Data_Bin\\20127261_KTLT\\Final_TH\\final-clc04\\20\\classData\\20clc01\\nguyen.csv")
     if (!f.is_open()) cout << "ERROR !!!" << '\n';

     string fullname;
     string gender;
     string socialID;
     string studentID;
     string DoB;
     string No;

}

bool writeRecord2File(string file_name, string field_1, string field_2, string field_3, string field_4, string field_5, string field_6)
{
    ofstream file;
    file.open(file_name, ios::app);
    file << field_1 << "," << field_2 << ", " << field_3 << ", " << field_4 << ", " << field_5 << ", " << field_6 << endl;
    file.close();

    return true;
}


string input()
{
    string t;
    cout<<"Enter data: ";
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
    display(pHead);

    ofstream f;
    f.open("E:/Data_Bin/20127261_KTLT/Final_TH/final-clc04/20/classData/20clc01/nguyen.txt");

    f << text << endl;*/

    string text1 = input();
    string text2 = input();
    string text3 = input();
    string text4 = input();
    string text5 = input();
    string text6 = input();
    bool write2file = writeRecord2File("E:\\Data_Bin\\20127261_KTLT\\Final_TH\\final-clc04\\20\\classData\\20clc01\\yahoo.txt", text1, text2, text3, text4, text5, text6);

    return 0;
}