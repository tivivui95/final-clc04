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
    cout << "|" << setw(33) << string1 << setw(33) << string2 << setw(33) << "|" << endl;
}

void UIgrid_2_1_Short(string string1, string string2) {
    cout << "|" << setw(19) << string1 << setw(19) << string2 << setw(21) << "|" << endl;
}

void UIInput(string label) {
    cout << "|" << setw(20) << label;
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