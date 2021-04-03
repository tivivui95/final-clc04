#include "Header.h"

int main() {
    // Setting for UTF-8, Encoding for Vietnamese characters, using cout << " Tiếng Việt " << flush; to cout Vietnamese text in console
    SetConsoleOutputCP( CP_UTF8 );
    setvbuf( stdout, nullptr, _IONBF, 0 );
    MBuf buf;
    std::cout.rdbuf( &buf );
    // End Setting

    Node* head = nullptr;
    Node* head2 = nullptr;
    fstream f;
    // Navigation(choice);

   /* CreateSubject(head);
    Display(head);*/
    // AddAndDisplayStudent(head);
    // CreateSchoolYear(head);

    return 0;
}