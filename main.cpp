#include "Header.h"

int main() {
    // Setting Vietnamese, don't change
    SetConsoleOutputCP( CP_UTF8 );
    setvbuf( stdout, nullptr, _IONBF, 0 );
    MBuf buf;
    std::cout.rdbuf( &buf );
    // First Screen to Login
    system("cls");
    UITitle("Welcome to HCMUS Portal!");
    UIgrid_2_1_Long("1. Login", "2. Exit");    
    UILineLong();
    int input; UICin(input);
    system("cls"); LoginM* data = nullptr;
    bool check = LoginMain(data);
    if ((input == 1) && check) 
    {
        system("cls");
        Staff* CurS = new Staff;
        CurS->UserId = data->id;
        CurS->Username = data->LoginId;
        ifstream f; string temp;
        f.open("OverallData/staffData.txt");
        getline(f, temp, '\n');
        // f.ignore(256,'\n');
        while(getline(f, temp,',')) 
            if (temp == data->LoginId) 
            { getline(f, CurS->FullName, ','); break; }
            // cout << temp << flush << endl;
        f.close();
        DisplayNav(CurS);
        // UILineLong();
        // UIgrid_3_1_Long("Username: " + data->LoginId,"id: " + data->id,"You are " + data->type);
        // cout << "id: " << data->id << endl;
        // cout << "You are " << data->type << endl;
    } else return 0;
    // End login, Id of user located in data variable, you can use it by data.LoginId
    // UILineLong();
    system("pause");
    
    return 0;
}