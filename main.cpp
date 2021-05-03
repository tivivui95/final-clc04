#include "header.h"
int main(int argc, char* argv[]) {
    SetConsoleTitleA("Learning Management System");
    HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect); 
 
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 842, 450, TRUE);
    // Setting Vietnamese, don't change
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IONBF, 0);
    MBuf buf;
    std::cout.rdbuf(&buf);
    // Start here
    // cout << getCurrentYear() << flush;
    // cout << currentTime();
    // cout << getInfo("20127007") << flush;
    setColor(0, 13);
    UITitle("LEARNING MANAGEMENT SYSTEM");
    setColor(0, 10);
    string username, type;
    Login(username, type);
    // Need UI here
    system("cls");
    UIgrid_2_1_Long("Username:" + username, "Type:" + type);
    if (type == "staff") staffDashBoard(username);
    else if (type == "student") studentDasboard(username);
    return 0;
}


void addtoSNode(stringNode*& head, string add) {
    stringNode* Temp = head; int i = -1;
    while (Temp != nullptr)
    {
        i = Temp->index;
        Temp = Temp->next;
    }
    // if (Temp=nullptr) Temp = new stringNode;
    Temp = new stringNode;
    Temp->data = add;
    cout << Temp->data;
    Temp->index = i + 1;
    cout << " " << Temp->index << " ";
    Temp->next = nullptr;
}

void deleteSNode(stringNode*& head) {
    stringNode* Temp = head;
    while (head != nullptr)
    {
        Temp = head;
        head = head->next;
        delete Temp;
    }
    delete Temp;
}

string currentTime() {
    time_t rawtime;
    struct tm* timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
    std::string str(buffer);

    return str;
}

void displaycList(courseList* cL) {
    while (cL != nullptr)
    {
        cout << cL->id << " " << cL->name << endl;
        cL = cL->next;
    }
}

void getData(ifstream& r, courseList*& clist) {
    string temp;
    clist = new courseList;
    courseList* cur = clist;
    // r.ignore(100,'\n');  
    while (getline(r, cur->id, ',')) {
        getline(r, cur->name, ',');
        // cout << "ID:" << cur->id << endl;
        getline(r, cur->teacher, ',');
        getline(r, temp, ','); cur->credits = stoi(temp);
        // cout << "Credits:" << cur->credits << endl;
        getline(r, temp, ','); cur->max = stoi(temp);
        getline(r, cur->s1day, ',');
        getline(r, cur->s1ses, ',');
        getline(r, cur->s2day, ',');
        getline(r, cur->s2ses, ',');
        getline(r, temp, '\n');
        cur->next = new courseList;
        cur = cur->next;
        cur->next = nullptr;
    }
    if (cur->max == 0) cur = nullptr;
}

courseList* getCourseList() {
    ifstream r;
    r.open("Data/general/course/list.txt");
    courseList* clist = nullptr;
    getData(r, clist);
    r.close();
    return clist;
}

void writeCourseList(courseList* clist) {
    courseList* cur = clist;
    ofstream w;
    w.open("Data/general/course/list.txt");
    cur = clist;
    while (cur != nullptr) {
        if (cur->max != 0)
            w << cur->id << "," << cur->name << "," << cur->teacher << "," << cur->credits << "," << cur->max << "," << cur->s1day << "," << cur->s1ses << "," << cur->s2day << "," << cur->s2ses << ",\n";
        cur = cur->next;
    }
    w.close();
}

string getInfo(string username) {
    ifstream classes, find;
    classes.open("Data/general/class.txt");
    string name;
    while (getline(classes, name, ' '))
    {
        find.open("Data/student/" + name + ".txt");
        while (getline(find, name, ','))
        {
            if (name == username) {
                string out;
                getline(find, out, '\n');
                find.close();
                classes.close();
                return name + "," + out;
            }
        }
    }
    return name;
}

courseList* getEnrollC(string username) {
    ifstream course, find;
    courseList* allCourse = getCourseList();
    courseList* cur = allCourse;
    string temp;
    courseList* tmpC = nullptr;
    while (cur != nullptr) {
        find.open("Data/general/course/" + cur->id + "/students.txt");
        int check = 0;
        while (getline(find, temp, ','))
        {
            if (temp == username) check++;
        }
        find.close();
        if (check == 0) if (tmpC != nullptr) {
            tmpC->next = cur->next;
            delete cur;
            cur = tmpC->next;
        }
        else {
            allCourse = allCourse->next;
            delete cur;
            cur = allCourse;
        }
        else {
            tmpC = cur;
            cur = cur->next;
        }
    }
    return allCourse;
}
