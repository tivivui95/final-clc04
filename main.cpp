#include "Header.h"

int main() {
    // First Screen to Login
    system("cls");
    UITitle("Welcome to HCMUS Portal!");
    UIgrid_2_1_Long("1. Login", "2. Exit");    
    UILineLong();
    int input; cin >> input;
    system("cls"); LoginM* data = nullptr;

    if ((input == 1) && LoginMain(data)) 
    {
        system("cls");
        cout << "Username: " << data->LoginId << endl;
        cout << "id: " << data->id << endl;
        cout << "You are " << data->type << endl;
    } else return 0;
    // End login, Id of user located in data variable, you can use it by data.LoginId
    UILineLong();
    system("pause");
    
    return 0;
}