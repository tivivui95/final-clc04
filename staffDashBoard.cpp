#include "Header.h"

void createNewYear() {

}

void maindashboard(int input) {
    switch (input)
    {
    case 1:
        {
            createNewYear();
            break;
        }
    case 2:
        {
            AddNewSubject();
            break;
        }
    case 3:
        {
            DeleteSubject();
            break;
        }
    
    default:
        break;
    }
}