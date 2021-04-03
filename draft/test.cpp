// Có gì cần test mà ko muốn bỏ vô thì cứ code ở đây nha
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream f;
    string a;
    f.open("text.txt");
    while (getline(f, a)) {
        cout << a << endl;
    }
    f.close();
    return 0;
}