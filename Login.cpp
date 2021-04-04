#include "Header.h"

bool LoginMain(LoginM* &data) {
    data = new LoginM;
    string username, password, temp;
    UITitle("LOGIN PAGE");
    UIInput("Username: "); cin >> username;
    UIInput("Password: "); cin >> password;
    ifstream f;
    f.open("OverallData/loginData.txt");
    getline(f, temp, '\n');
    while (getline(f,temp,','))
        if (temp == username) 
        {
            data->LoginId=temp; getline(f,temp,','); 
            if (temp == password) 
            {
                getline(f,temp,','); data->id=temp;
                getline(f,temp,','); data->type=temp;
                f.close(); Loading();
                UITitle("Login Successful! You will be redirected shortly!");
                Sleep(1500); 
                return true;
            } 
            else 
            { 
                data = nullptr; f.close(); UITitle("Login Fail!"); Sleep(1000); 
                system("cls"); return LoginMain(data);
            }
        } 
        else getline(f, temp, '\n');
        f.close(); UITitle("Login Fail!"); Sleep(1000); system("cls"); return LoginMain(data);
}