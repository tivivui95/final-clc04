#include "Header.h"

void UITitle(string input) {
    UILineLong();
    cout << setw(60) << input << endl;
    UILineLong();
}

void UILineLong() {
    for (int i = 0; i < 100; i++) cout << "-"; cout << endl;
}

void UILineShort() {
    for (int i = 0; i < 60; i++) cout << "-"; cout << endl;
}

void UIgrid_2_1_Long(string string1, string string2) {
    cout << "|" << setw(33) << string1 << setw(33) << string2 << setw(33) << "|" << flush << endl;
}

void UIgrid_2_1_Short(string string1, string string2) {
    cout << "|" << setw(19) << string1 << setw(19) << string2 << setw(21) << "|" << flush << endl;
}

void UIgrid_3_1_Long(string string1, string string2, string string3) {
    cout << "|" << setw(25) << string1 << setw(25) << string2 << setw(25) << string3 << setw(24) << "|" << flush << endl;
}

void UIgrid_3_1_Short(string string1, string string2, string string3) {
    cout << "|" << setw(15) << string1 << setw(15) << string2 << setw(15) << string3 << setw(14) << "|" << flush << endl;
}

void UIInput(string label) {
    cout << "| >> " << setw(20) << label << flush;
}

void Loading() {
    system("cls");
    for (int i = 0; i < 40; i++)
    {
        UILineShort();
        cout << setw(2) << i*2.5 << "%";
        for (int j = 0; j < i; j++) cout << "=";
        cout << ">" << endl; UILineShort(); Sleep(20); system("cls");
    }
    
}

int UICin(int& n) {
    cout << ">> "; cin >> n; return n;
}

void UIgrid_1_1_Long(string string) {
    cout << "|" << setw(30) << string << setw(69) << "|" << flush << endl;
}

void UIgrid_1_1_Short(string string) {
    cout << "|" << setw(30) << string << setw(29) << "|" << flush << endl;
}