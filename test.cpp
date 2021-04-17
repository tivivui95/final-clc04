#include <iostream>
#include <fstream>
using namespace std;
int main() {
    int a[4];
    fstream r;
    r.open("text.txt");
    for (int i = 0; i< 4; i++) r >> a[i];
    r.close();
    a[1] = 123;
    ofstream k;
    k.open("text.txt", ios::trunc);
    for (int i = 0; i < 4; i++) k << a[i] << "\n";
    k.close();
}
// Test File
// Woww