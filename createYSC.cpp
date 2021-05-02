#include "Header.h"

void createYSC()
{
	system("cls");

	char tmpY[500];
	cout << "Year: ";
	cin.ignore(1000, '\n');
	cin.get(tmpY, 500, '\n');
	char* year = new char[strlen(tmpY) + 1];
	strcpy(year, tmpY);
	int n = 0;

	Year* pHead = nullptr;
	if (!year_is_exist(pHead, n, year))
    {
		createNewYear(pHead, n, year);
	}
	else
    {
		cout << "You have this year already !!!" << endl;
	}
	char tmpS[500];
	cout << "Semester: ";
	cin.ignore(100, '\n');
	cin.get(tmpS, 500, '\n');
	char* semester = new char[strlen(tmpS) + 1];
	strcpy(semester, tmpS);
	n = 0;

	Year* pHead1 = nullptr;
	if (!semester_is_exist(pHead1, n, year, semester))
    {
		createNewSemester(pHead1, n, year, semester);
	}
	else
    {
		cout << "You have this semester already !!!" << endl;
	}


	char tmpC[500];
	cout << "Class: ";
	cin.ignore(100, '\n');
	cin.get(tmpC, 500, '\n');
	char* course = new char[strlen(tmpC) + 1];
	strcpy(course, tmpC);

	n = 0;
	Year* pHead2 = nullptr;
	if (!course_is_exist(pHead2, n, year, semester, course))
    {
		createNewCourse(pHead2, n, year, semester, course);
		//introDone();
	}
	else
	{
		cout << "You have this course already !!!" << endl;

		system("pause");
	}

	deleteYear(pHead);
	deleteSemester(pHead1);
	deleteCourse(pHead2);

	system("pause");
}

// void inputYSC(char year[], char semester[], char className[]) {
// 	//year
// 	ifstream in;
// 	in.open("20/yearData/Year.txt");
// 	if (!in.is_open())
//     {
// 		cout << "ERROR !!!";
// 		return;
// 	}
// 	else {
// 		system("cls");
// 		//cout << "===== LIST =====\n";
// 		char a[20];
// 		int n;
// 		in >> n;
// 		for (int i = 0; i < n; ++i) {
// 			in.ignore(100, '\n');
// 			in.get(a, 20, '\n');
// 			cout << "[" << i + 1 << "]. " << a << '\n';
// 		}
// 		cout << "==================\n";
// 		cout << "Please input year: ";
// 		cin.ignore(100, '\n');
// 		cin.get(year, 20, '\n');
// 	}

// 	in.close();

// 	if (!year_is_exist(pHead, n, year))
//     {
// 		system("cls");
// 		cout << "Wrong!, Please enter again !\n";
// 		return inputYSC(year, semester, className);
// 	}

// 	//semester
// 	char fileAdd[499] = {};
// 	strcat(fileAdd, "D:/Github/CS162-19CTT1-19125059/ZPMS/");
// 	strcat(fileAdd, year);
// 	strcat(fileAdd, "/");
// 	strcat(fileAdd, "Semester.txt");

// 	in.open(fileAdd);
// 	if (!in.is_open()) {
// 		cout << "Error at input semester\n";
// 		return;
// 	}
// 	else {
// 		char a[20];
// 		system("cls");
// 		cout << "==== LIST ====\n";
// 		int n;
// 		in >> n;
// 		in.ignore(20, '\n');
// 		for (int i = 0; i < n; ++i) {
// 			in.get(a, 20, '\n');
// 			in.ignore(20, '\n');
// 			cout << "[" << i + 1 << "]. " << a << '\n';
// 		}
// 		cout << "==================\n";
// 		cout << "Please input semester: ";
// 		cin.ignore(10, '\n');
// 		cin.get(semester, 10, '\n');
// 	}
//     in.close();

// 	if (!isExistSem(year, semester)) {
// 		system("cls");
// 		cout << "Wrong!, Please enter again !\n";
// 		return inputYSC(year, semester, className);
// 	}

// 	char fileAdd1[500] = {};
// 	strcat(fileAdd1, "D:/Github/CS162-19CTT1-19125059/ZPMS/");
// 	strcat(fileAdd1, year);
// 	strcat(fileAdd1, "/");
// 	strcat(fileAdd1, semester);
// 	strcat(fileAdd1, "/");
// 	strcat(fileAdd1, "Class.txt");
// 	in.open(fileAdd1);

// 	cout << fileAdd1 << '\n';

// 	if (!in.is_open()) {
// 		cout << "Error opening\n";
// 		return;
// 	}
// 	else {
// 		char a[20];
// 		system("cls");
// 		int n;
// 		in >> n;
// 		for (int i = 0; i < n; i++) {
// 			in.ignore(20, '\n');
// 			in.get(a, 20, '\n');
// 			cout << "[" << i + 1 << "]. " << a << '\n';
// 		}
// 		cout << "==================\n";
// 		cout << "Please input class: ";
// 		cin.ignore(20, '\n');
// 		cin.get(className, 20, '\n');
// 	}
// 	in.close();

// 	if (!isExistClass(className, semester, year)) {
// 		system("cls");
// 		cout << "Wrong!, Please enter again !\n";
// 		return inputYSC(year, semester, className);
// 	}
// 	return;
// }
