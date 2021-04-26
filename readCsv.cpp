#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
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
    string temp = "temp";
    f.ignore(1,'\n');
    while (temp!="")
    {
        getline(f, temp, '\n');
        getline(f, temp, ',');
        cout << "No: " << temp << flush << endl;
        getline(f, temp, ',');
        cout << "SID: " << temp << flush << endl;
        getline(f, temp, ',');
        cout << "Name: " << temp << flush << endl;
        getline(f, temp, ',');
        cout << "DOB: " << temp << flush << endl;
        getline(f, temp, ',');
        cout << "Gender: " << temp << flush << endl;
        cout << "------------------------------------------" << endl;
        // temp.erase(temp.find("\n"));

    }
    return 0;
}
