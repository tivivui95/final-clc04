#include "Header.h"

void DisplayNavStaff(Staff* &data) {
    UILineLong();
    UIgrid_3_1_Long("1. View Profile", "2. Change password", "3. Log out");
    UITitle("Hello " + data->FullName);
}

void NavProcess(int input) {
    
}

void DisplayNavStudent(LoginStudent* LStu) {
    UILineLong();
    UIgrid_3_1_Long("1. View Profile", "2. Change password", "3. Log out");
    UITitle("Hello " + LStu->FullName);
}