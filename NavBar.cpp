#include "Header.h"

void DisplayNav(Staff* &data) {
    UILineLong();
    UIgrid_3_1_Long("1. View Profile", "2. Change password", "3. Log out");
    UITitle("Welcome " + data->FullName);
}