#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
// #include <string.h>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <cstring>
using namespace std;

#define MaxStudent 50;
// Setting accent, Don't change anything in this class, it's for Vietnamese character
typedef struct _SMALL_RECT {
    SHORT Left;
    SHORT Top;
    SHORT Right;
    SHORT Bottom;
} SMALL_RECT;

using namespace std;

// Setting Vietnamese character
class MBuf: public std::stringbuf {
public:
    int sync() {
        fputs( str().c_str(), stdout );
        str( "" );
        return 0;
    }
};
// Start here
// Struct variable

// Functions
// Login function

// typedef struct _SMALL_RECT {
//     SHORT Left;
//     SHORT Top;
//     SHORT Right;
//     SHORT Bottom;
// } SMALL_RECT;


void Login(string &username, string &type);
bool checkLogin(string username, string password, string &type);
// Dashboard
void staffDashBoard(string username);
void studentDasboard(string username);
// Staff Dashboard
void createYear();
void manageYear();
// Manage Year
void manageClass();
void createSem(string curYear);
void manageSem(string curYear, string curSem);
void manageClass();
// Manage Semester
void createCourse(string curYear, string curSem);
void createEnrollPeriod();
void manageCourse();
// Manage course
void viewCourse(string courseName);
void editCourse(string courseName);
void deleteCourse(string courseName);
void exportcsvfile(string courseName);
void importScore(string courseName);
// Manage Class
void createClass();
void editClasses();
void addNewStu(string line);
void editClass(string line);
void caculateGPA();
// Student
void enrollnow(string username);
void viewMyCourse(string username);
void viewMyScore(string username);
// Other functions
string getCurrentYear();
string getCurrentSem(string curYear);

string getInfo(string username);
string currentTime();
struct stringNode {
    string data;
    int index;
    stringNode* next;
};

struct courseList {
    string id, name, teacher, s1day, s1ses, s2day, s2ses;
    int credits, max;
    courseList* next;
};
void deleteSNode(stringNode*& head);
void addtoSNode(stringNode* &head, string add);
void displaycList(courseList * cL);
void getData(ifstream &r, courseList * &clist);
courseList* getCourseList();
void writeCourseList(courseList* clist);
courseList* getEnrollC(string username);

// UI
void setColor(int background_color, int text_color);
void UIgrid_1_1_Short(string string);

void UIgrid_1_1_Long(string string);
int UICin(int& n);
void Loading();
void UIInput(string label);
void UIgrid_3_1_Short(string string1, string string2, string string3);
void UIgrid_3_1_Long(string string1, string string2, string string3);
void UIgrid_2_1_Short(string string1, string string2);
void UIgrid_2_1_Long(string string1, string string2);
void UILineShort();
void UILineLong();
void UITitle(string input);
#endif
