#include "Header.h"

void LoginMain(string& loginId, string& Id, string& type, bool& check) {
    string username, password, temp;
    UITitle("LOGIN PAGE");
    UIInput("Username: "); cin >> username;
    UIInput("Password: "); cin >> password;
    ifstream f;
    f.open("OverallData/loginData.txt");
    getline(f, temp, '\n');
    while (getline(f,temp,','))
        if (temp==username) 
        {
            loginId==temp; cout << loginId; system("pause"); getline(f,temp,','); 
            if (temp == password) 
            {
                // getline(f,temp,','); data->id==temp;
                // getline(f,temp,','); data->type==temp;
                // f.close(); data->check = true;
                
                Loading();
                UITitle("Login Successful! You will be redirected shortly!");
                Sleep(500);
                break;
            } else 
            {
                f.close(); check = false; UITitle("Login Fail!"); Sleep(1000); 
                system("cls"); 
                return LoginMain(loginId,Id,type,check);
            }
        } else getline(f, temp, '\n');
    if (check!=true) 
    {
        f.close(); UITitle("Login Fail!"); 
        Sleep(1000); system("cls"); return LoginMain(loginId,Id,type,check);
    }
}