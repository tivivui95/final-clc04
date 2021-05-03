#include "header.h"

void UITitle(string input) {
    UILineLong();
    cout << setw(60) << input << flush << endl;
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
    cout << "|" << setw(30) << string1 << setw(30) << string2 << setw(30) << string3 << setw(9) << "|" << flush << endl;
}

void UIgrid_3_1_Short(string string1, string string2, string string3) {
    cout << "|" << setw(15) << string1 << setw(15) << string2 << setw(15) << string3 << setw(14) << "|" << flush << endl;
}

void UIInput(string label) {
    cout << "| >> " << setw(20) << label << flush;
}

void Loading() {
    system("cls");
    for (int i = 0; i < 50; i++)
    {
        UILineShort();
        cout << "[";
        cout << setw(5) << i*2 << "%" << "  ";
        for (int j = 0; j < i; j++) cout << "=";
        for (int k = 50-i; k > 0; k--) cout << "-";
        cout << "]" << endl; UILineShort(); Sleep(10); system("cls");
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


// void SetConsoleTitle()
// {
//     SetConsoleTitleA("Learning Management System");
    
// }

// setColor(0, 10) cho màu xanh, setColor(0, 13) cho màu hồng, setColor(0, 14) cho màu vàng
void setColor(int background_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = background_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

// (120, 150)
// void SetWindowSize(SHORT width, SHORT height)
// {
//     HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

//     SMALL_RECT WindowSize;
//     WindowSize.Top = 0;
//     WindowSize.Left = 0;
//     WindowSize.Right = width;
//     WindowSize.Bottom = height;

//     SetConsoleWindowInfo(hStdout, 1, &WindowSize);
// }
// >>>>>>> Stashed changes
