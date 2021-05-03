#include "header.h"
int input;
void Login(string &username, string &type) {
    // cout: Welcome to...
    string password;
    bool a = false;
    do
    {
        // Need UI here
        if (a) cout << "Pls try again.";
        cout << "username:"; 
        cin >> username;
        cout << "password:";
        cin >> password;
        a = checkLogin(username, password, type);
    } while (!a);
    // system("pause");
}

bool checkLogin(string username, string password, string &type) {
    ifstream check;
    check.open("Data/userdata.txt");
    string temp;
    getline(check, temp, '\n');
    while(getline(check, temp, ','))
    if (temp==username) {
        getline(check, temp, ',');
        if (temp==password)
        {
            getline(check, temp, ',');
            type = temp;
            check.close();
            return true;
        } 
        else {
            check.close();
            return false;
        } 
    }
    check.close();
    return false;
}

void staffDashBoard(string username) {
    ifstream infile;
    infile.open("Data/staff/staffData.txt");
    string temp;
    while(getline(infile, temp, ',')) 
        if (temp == username) {
            getline(infile, temp, ',');
            break;
        }
    cout << "Welcome " << temp << flush << endl; 
    // Add UI
    infile.close();
    cout << "Choose 1 option:" << endl;
    ifstream yearlist; int tmp;
    yearlist.open("Data/general/schoolyear.txt");
    yearlist >> tmp; 
    // Add UI
    if (tmp>0) {
        cout << "1. Create new Schoolyear.\n2. Manage this year.\n";
    } else cout << "1. Create Schoolyear.\n";
    
    cin >> input;
    yearlist.close();
    switch (input)
    {
    case 1:
        createYear();
        break;
    case 2:
        manageYear();
        break;
    case 0:
        return;
    default:
        break;
    }
    staffDashBoard(username);
}

void createYear() {
    ifstream year;
    ofstream temp;
    year.open("Data/general/schoolyear.txt");
    temp.open("temp.txt");
    string a;
    while(getline(year, a, '\n')) temp << a << endl;
    year.close(); temp.close();
    temp.open("Data/general/schoolyear.txt");
    year.open("temp.txt");
    while (getline(year, a, '\n'))
    temp << a << endl;
    // Need UI
    int n; cin >> n; temp << n << " "; // Need UI
    cin >> a; temp << a;
    year.close(); temp.close();
    temp.open("Data/general/"+ to_string(n) +"sem.txt");
    temp.close();
    manageYear();
}

void manageYear() {
    
    string curYear = getCurrentYear();
    fstream infile;
    ofstream outfile;
    string curSem = getCurrentSem(curYear);
    // system("pause");
    if (curSem == "s1" || curSem == "s2" || curSem == "s3") cout << "1. Create Semester\n2. Manage Current Semester\n3. Manage Classes" << flush;
    else cout << "1. Create Semester" << flush;
    cin >> input;
    switch (input)
    {
    case 1:
        createSem(curYear);
        break;
    case 2:
        manageSem(curYear, curSem);
        break;
    case 3:
        manageClass();
        break;
    default:
        break;
    }
}

void createSem(string curYear) {
    ofstream f;
    f.open("Data/general/"+ curYear +"sem.txt");
    cout << "Choose semester to create:\n1. s1\n2. s2\n3. s3." << flush << endl;
    
    cin >> input;
    switch (input)
    {
    case 1:
        f << "s1";
        break;
    case 2:
        f << "s1 s2";
        break;
    case 3:
        f << "s1 s2 s3";
        break;    
    default:
        break;
    }
    f.close();
}

void manageSem(string curYear, string curSem) {
    // Add UI
    cout << "1. Create Course.\n2. Create Enroll Period.\n3. Manage Course.\n";
     cin >> input;
    switch (input)
    {
    case 1:
        createCourse(curYear, curSem);
        manageSem(curYear, curSem);
        break;
    case 2:
        createEnrollPeriod();
        manageSem(curYear, curSem);
        break;
    case 3:
        manageCourse();
        manageSem(curYear, curSem);
        break;
    case 4:
        manageSem(curYear, curSem);
        break;
    default:
    return;
        break;
    }
}

void createCourse(string curYear, string curSem) {
    fstream addList;
    ifstream f;
    f.open("Data/general/course/list.txt");
    f.close();
    addList.open("Data/general/course/list.txt", ios::app);
    string temp; 
    // Add UI;
    cout << "Course ID: " << flush;
    cin.ignore(100, '\n');
    getline(cin, temp);
    char dir[] = "Data/general/course/";
    int n = temp.length();
    // declaring character array
    char char_array[n + 1];
    // copying the contents of the
    // string to char array
    strcpy(char_array, temp.c_str());
    strcat(dir, char_array);
    CreateDirectoryA(dir, NULL);
    ofstream create;
    create.open("Data/general/course/" + temp + "/students.txt");
    create.close();
    create.open("Data/general/course/" + temp + "/scores.txt");
    create.close();
    addList << temp << ",";
    cout << "Course Name: " << flush;
    getline(cin, temp);
    addList << temp << ",";
    cout << "Teacher Name: " << flush;
    getline(cin, temp);
    addList << temp << ",";
    cout << "Nums of Credits: " << flush;
    cin >> temp; addList << temp << ",";
    int num = 50;
    cout << "Max Students: " << flush;
    cin >> num; addList << num << ",";
    cout << "Session 1 Day (2-7) from Mon to Sat: ";
    int tempNum; cin >> tempNum; addList << tempNum << ",";
    cout << "Session 1 Time (1-4):\n\t1. 07:30\n\t2. 09:30\n\t3. 13:30\n\t4. 15:30\n";
    cin >> tempNum; addList << tempNum << ",";
    cout << "Session 2 Day (2-7) from Mon to Sat: ";
    cin >> tempNum; addList << tempNum << ",";
    cout << "Session 2 Time (1-4):\n\t1. 07:30\n\t2. 09:30\n\t3. 13:30\n\t4. 15:30\n";
    cin >> tempNum; addList << tempNum << "," << endl;
    addList.close();
    return;
}

void createEnrollPeriod() {
    int day, month, year;
    cout << "Choose Start Year: "; cin >> year;
    cout << "Choose Start Month (1-12): "; cin >> month;
    cout << "Choose Start Day (1-31): "; cin >> day;
    ofstream enroll;
    enroll.open("Data/general/enrollTime.txt");
    enroll << day << "-" << month << "-" << year << endl;
    cout << "Choose End Year: "; cin >> year;
    cout << "Choose End Month (1-12): "; cin >> month;
    cout << "Choose End Day (1-31): "; cin >> day;
    enroll << day << "-" << month << "-" << year << endl;
    enroll.close();
}

void manageCourse() {
    cout << "Courses:\n1.View Course Students\n2.Edit\n3.Delete\n4. Import Score (csv file)\n";
    cin >> input;
    ifstream f;
    f.open("Data/general/course/list.txt");
    // f.ignore(100, '\n');
    string temp; stringNode* List = nullptr;
    // system("pause");
    int cou = 0;
    while (getline(f, temp, ','))
    {
        ++cou;
        addtoSNode(List, temp);
        cout << cou << ". " << temp << flush;
        getline(f, temp, ','); cout << setw(25) << temp;
        getline(f, temp, ','); cout << setw(20) << temp;
        getline(f, temp, ','); cout << setw(4) << temp;
        getline(f, temp, ','); cout << setw(4) << temp;
        getline(f, temp, ','); cout << setw(4) << temp;
        getline(f, temp, ','); cout << setw(4) << temp;
        getline(f, temp, ','); cout << setw(4) << temp;
        getline(f, temp, ','); cout << setw(4) << temp << "\n";
        // system("pause");
        getline(f, temp, '\n');
    }
    f.close();
    cout << "Choose course (Type course ID):"; 
    string input2;
    cin >> input2;
    switch (input)
    {
    case 1:
        viewCourse(input2);
        break;
    case 2:
        editCourse(input2);
        break;
    case 3:
        deleteCourse(input2);
    case 4:
        importScore(input2);
    default:
        break;
    }
    deleteSNode(List);
}

void importScore(string courseName) {
    ofstream w;
    w.open("Data/general/course/" + courseName + "/scores.txt");
    ifstream r;
    cout << "Enter directory:";
    string dir, temp; cin >> dir;
    r.open(dir);
    getline(r, temp);
    w << temp;
    r.close(); w.close();
}

void editCourse(string courseName) {
    courseList * clist = getCourseList();
    // cur = clist;
    courseList * cur = clist;
    displaycList(clist);
    // cout << "Clist top:" << clist->id << endl;
    while (cur!=nullptr && cur->id != courseName)
    cur = cur->next;
    // cout << cur->id << endl;
    cout << "Choose field to edit: \n1. Name\n2. Teacher\n3. Credits\n4. Session 1 Day\n 5. Session 1 Time\n6. Session 2 Day\n 7. Session 2 Time\n8. Max students\n";
    cin >> input;
    
    cout << "Enter field data:" << flush;
    cin.ignore(100, '\n');
    switch (input)
    {
    case 1:
        getline(cin, cur->name);
        break;
    case 2:
        getline(cin, cur->teacher);
        break;
    case 3:
        cin >> cur->credits;
        break;
    case 4:
        cin >> cur->s1day;
        break;
    case 5:
        cin >> cur->s1ses;
        break;
    case 6:
        cin >> cur->s2day;
        break;
    case 7:
        cin >> cur->s2ses;
        break;
    case 8:
        cin >> cur->max;
        break;
    default:
        break;
    }
    writeCourseList(clist);
}

void deleteCourse(string courseName) {
    courseList* clist = getCourseList();
    courseList * cur = clist, *temp;
    displaycList(clist);
    // cout << "Clist top:" << clist->id << endl;
    while (cur!=nullptr && cur->id != courseName) {
        temp = cur;
        cur = cur->next;
    }
    temp->next = cur->next;
    delete cur;
    writeCourseList(clist);
}

void viewCourse(string courseName) {
    ifstream f;
    f.open("Data/general/course/" + courseName + "/students.txt");
    string temp;
    while (getline(f, temp, '\n')) cout << temp << endl;
    f.close();
    cout << "1. Export csv file" << endl;
    cin >> input;
    if (input == 1) exportcsvfile(courseName);
}

void exportcsvfile(string courseName) {
    ifstream f; ofstream w;
    w.open("Export/" + courseName + "-students.csv");
    f.open("Data/general/course/" + courseName + "/students.txt");
    string temp;
    while (getline(f, temp, '\n')) w << temp << endl;
    f.close(); w.close();
}

void manageClass() {
    cout << "1. Create New Class.\n2. Edit Class Info.\n3. Caculate GPA\n";
    cin >> input;
    switch (input)
    {
    case 1:
        createClass();
        break;
    case 2:
        editClasses();
    case 3:
        caculateGPA();
    default:
        break;
    }
}

void caculateGPA() {
    ifstream classes, r, find, score;
    ofstream save, w;
    int sum = 0;
    string temp, id, search;
    classes.open("Data/general/class.txt");
    while (getline(classes, temp, ' '))
    {
        r.open("Data/student/" + temp + ".txt");
        int cou = 0;
        while(getline(r,temp,',')) {
            getline(r,temp,',');
            id = temp;
            cou++;
            ifstream course;
            course.open("Data/general/course/list.txt");
            while (getline(course, temp, ',')) {
                score.open("Data/general/course/" + temp + "/scores.txt");
                while (getline(score, temp, ','))
                {
                    if (temp == id) {
                        for (int i = 0; i < 3; i++) getline(score, temp, ',');
                        getline(score, temp, ',');
                        if (sum == 0) sum += stoi(temp);
                        else sum = (sum + stoi(temp))/2;
                        ofstream tmptxt;
                        tmptxt.open("temp.txt");
                        tmptxt << getInfo(id) << "," << sum << endl;
                        tmptxt.close();
                    } 
                }
                find.open("temp.txt");
                fstream appendtxt;
                appendtxt.open("temp2.txt", ios::app);
                getline(find,temp); appendtxt << cou << "," << temp;
                appendtxt.close(); find.close();
                score.close();
                getline(course, temp, '\n');
            }
            course.close();
            getline(r, temp, '\n');
        }
        r.close();
        r.open("temp2.txt"); w.open("Data/student/" + temp + ".txt");
        getline(r, temp); w << temp;
        r.close();
        w.close();
    }
    classes.close();
}

void createClass() {
    cout << "Class name: "; string temp;
    cin >> temp;
    fstream a;
    a.open("Data/general/class.txt", ios::app);
    a << temp << " ";
    a.close();
    ofstream w;
    w.open("Data/student/" + temp + ".txt");
    w.close();
    // return;
}
void editClasses() {
    ifstream classes;
    classes.open("Data/general/class.txt");
    // stringNode* CArr = nullptr;
    string line;
    while (getline(classes, line, ' ')) cout << line << endl;
    cout << "Choose class: "; cin >> line;
    classes.close();
    cout << "1. Add new student\n2. Import csv file";
    cin >> input;
    switch (input)
    {
    case 1:
        addNewStu(line);
        break;
    case 2:
        editClass(line);
        break;
    default:
        // singleClass.close();
        return;
        break;
    }
    // singleClass.close();
}

void addNewStu(string line) {
    fstream singleClass, userdata;
    userdata.open("Data/userdata.txt", ios::app);
    singleClass.open("Data/student/" + line + ".txt", ios::app);
    // string line;
    cin.ignore(100, '\n');
    cout << "Student ID" << flush; getline(cin, line);
    userdata << "0," << line <<",";
    singleClass << line << ",";
    cout << "Student name: "; getline(cin, line);
    singleClass << line << ",";
    cout << "DOB (DD/MM/YYYY): "; cin >> line;
    userdata << line.at(0) << line.at(1) << line.at(3) << line.at(4) << line.at(6) << line.at(7) << line.at(8) << line.at(9) << ",student,\n";
    singleClass << line << ",";
    cout << "Gender: "; cin >> line;
    singleClass << line << ",";
    singleClass << endl;
    singleClass.close();
    userdata.close();
}

void editClass(string line) {
    fstream singleClass, userdata;
    userdata.open("Data/userdata.txt", ios::app);
    singleClass.open("Data/student/" + line + ".txt", ios::app);
    cout << "Enter your directory to csv file: ";
    cin >> line;
    ifstream f;
    f.open(line);
    while (getline(f, line, ',')) {
        singleClass << line << ",";
        getline(f, line, ',');
        singleClass << line << ",";
        userdata << "0," << line << ",0,student,\n";
        getline(f, line, '\n');
        singleClass << line << endl;
    } 
    f.close();
    singleClass.close();
    userdata.close();
}


void studentDasboard(string username) {
    string timenow = currentTime();
    cout << timenow << endl;
    int nowData[3];
    string s1(1, timenow.at(0));
    string s2(1, timenow.at(1));
    s1 += s2;
    // cout << s1 << flush;
    nowData[0] = stoi(s1);
    string s3(1, timenow.at(3));
    string s4(1, timenow.at(4));
    s3 += s4; nowData[1] = stoi(s3);
    string s5(1, timenow.at(6));
    string s6(1, timenow.at(7));
    string s7(1, timenow.at(8));
    string s8(1, timenow.at(9));
    s5 += s6 + s7 + s8; nowData[2] = stoi(s5);
    // cout << nowData[2] << flush << endl;
    // system("pause");
    ifstream f; string temp;
    f.open("Data/general/enrollTime.txt");
    int data[6];
    for (int i = 0; i < 6; i++)
    {
        if (i!=2)
        getline(f, temp, '-');
        else getline(f, temp, '\n');
        data[i] = stoi(temp);
        // cout << data[i] << flush << endl;
    }
    f.close();
    // system("pause");
    if (data[0] <= nowData[0] && nowData[0] <= data[3]) {
        if (data[1] <= nowData[1] && nowData[1] <= data[4])
            if (data[2] <= nowData[2] && nowData[2] <= data[5])
                enrollnow(username);
    }
    cout << "Choose option:\n1. View list of courses\n2. View score" << flush << endl;
    cin >> input;
    switch (input)
    {
    case 1:
        viewMyCourse(username);
        break;
    case 2:
        viewMyScore(username);
        break;
    default:
    studentDasboard(username);
        break;
    }
}

void viewMyScore(string username) {
    ifstream r;
    string temp;
    r.open("Data/general/course/list.txt");
    while(getline(r, temp, ',')) {
        ifstream score;
        score.open("Data/general/course/" + temp + "/scores.txt");
        cout << "Course ";
        getline(r, temp, ',');
        cout << temp << ": ";
        while(getline(score, temp, ',')) {
            if (temp == username) {
                for (int i = 0; i < 3; i++)
                getline(score, temp, ',');
                getline(score, temp, ',');
                cout << temp << endl;                
            }
            // getline(score, temp, '\n');
        }
        score.close();
    }
    r.close();
}

void viewMyCourse(string username) {
    courseList * mylist = getEnrollC(username);
    courseList* cur =mylist;
    while (cur!=nullptr) {

    }
    cout << cur->id << setw(25) << cur->name << setw(25) << cur->teacher << setw(5) << cur->max << setw(5) << cur->credits;
    if (cur->s1day=="2") cout << setw(6) << "Mon";
    else if (cur->s1day=="3") cout << setw(6) << "Tue";
    else if (cur->s1day=="4") cout << setw(6) << "Wed";
    else if (cur->s1day=="5") cout << setw(6) << "Thu";
    else if (cur->s1day=="6") cout << setw(6) << "Fri";
    else if (cur->s1day=="7") cout << setw(6) << "Sat";
    if (cur->s1ses=="1") cout << setw(6) << "7:30";
    else if (cur->s1ses=="2") cout << setw(6) << "9:30";
    else if (cur->s1ses=="3") cout << setw(6) << "13:30";
    else if (cur->s1ses=="4") cout << setw(6) << "15:30";
    if (cur->s2day=="2") cout << setw(6) << "Mon";
    else if (cur->s2day=="3") cout << setw(6) << "Tue";
    else if (cur->s2day=="4") cout << setw(6) << "Wed";
    else if (cur->s2day=="5") cout << setw(6) << "Thu";
    else if (cur->s2day=="6") cout << setw(6) << "Fri";
    else if (cur->s2day=="7") cout << setw(6) << "Sat";
    if (cur->s2ses=="1") cout << setw(6) << "7:30";
    else if (cur->s2ses=="2") cout << setw(6) << "9:30";
    else if (cur->s2ses=="3") cout << setw(6) << "13:30";
    else if (cur->s2ses=="4") cout << setw(6) << "15:30";
    cout << endl;
    cur = cur->next;
}

void enrollnow(string username) {
    cout << "Choose course: ";
    courseList * list = getCourseList();
    courseList * cur = list;
    int cou = 0;
    while (cur!=nullptr)
    {
        ++cou;
        cout << cou << ". " << cur->id << setw(25) << cur->name << setw(25) << cur->teacher << setw(5) << cur->max << setw(5) << cur->credits;
        // system("pause");
        cout << endl;
        cur = cur->next;
    }
    cin >> input;
    cur = list;
    for (int i = 0; i < input - 1; i++)
    cur = cur->next;
    cout << cur->id << flush << endl;
    ifstream r; fstream w;
    r.open("Data/general/course/" + cur->id + "/students.txt");
    w.open("Data/general/course/" + cur->id + "/students.txt", ios::app);
    cou = 0;
    string temp;
    while (getline(r, temp, '\n')) cou++;
    cout << cou << "\t" << cur->max << endl;
    
    if (cou > cur->max) cout << "Course is fulled. Choose another course." << endl;
    else w << ++cou << "," << getInfo(username) << flush << endl;
    w.close();
    r.close();
}


string getCurrentYear() {
    ifstream year;
    year.open("Data/general/schoolyear.txt");
    string a, temp;
    while(getline(year, a, ' ')) {     
        temp = a; 
        getline(year, a, '\n');
    } 
    year.close();
    return temp;   
}

string getCurrentSem(string curYear) {
    ifstream f;
    f.open("Data/general/"+ curYear +"sem.txt");
    string a, temp;
    while (getline(f, a, ' ')) temp = a;
    return temp;
}

