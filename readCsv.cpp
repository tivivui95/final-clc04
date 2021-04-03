#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <Windows.h>
using namespace std;
class MBuf: public std::stringbuf {
public:
    int sync() {
        fputs( str().c_str(), stdout );
        str( "" );
        return 0;
    }
};

int main() {
    SetConsoleOutputCP( CP_UTF8 );
    setvbuf( stdout, nullptr, _IONBF, 0 );
    MBuf buf;
    std::cout.rdbuf( &buf );
    ifstream f;
    f.open("import/20clc01.csv");
    string temp;
    while (getline(f, temp, ','))
    {
        cout << temp << flush << endl;
    } 
    return 0;   
}