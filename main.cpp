#include "Header.h"

int main() {
    // First Screen to Login
    system("cls");
    UITitle("Welcome to HCMUS Portal!");
    UIgrid_2_1_Long("1. Login", "2. Exit");    
    UILineLong();
    int input; cin >> input;
    system("cls"); string loginId, Id, type; bool check;
    LoginMain(loginId,Id,type,check);
    // if ((input == 1) && data->check) 
    // {
    //     cout << data->LoginId.c_str() << endl;
    //     cout << data->type.c_str() << endl;
    // } else return 0;
    // cout << data->LoginId.c_str() << endl;
    // cout << data->type.c_str() << endl;
    system("pause");
    // End login, Id of user located in data variable, you can use it by data.LoginId
    return 0;
}