#include "Header.h"

int countLine(ifstream& fin, int groups)
{
	char a[200];
	int count = 0;
	while (!fin.eof())
    {
		fin.getline(a, 200);
		++count;
	}
	return count / groups;
}

void cleanInputCourse(Schedule& c)
{
	delete[] c.courseID;
	delete[] c.courseName;
	delete[] c.Class;
	delete[] c.lec->name;
	delete c.lec;
	delete[] c.dayofweek;
}

void inputCourseData(Schedule& c, char id[], int maxno, char className[])
{
	char a[200];
	c.no = maxno + 1;

	c.courseID = new char[strlen(id) + 1];
	strcpy(c.courseID, id);

	//cin.ignore(100, '\n');
	cout << "Course Name: ";
	cin.get(a, 200, '\n');
	c.courseName = new char[strlen(a) + 1];
	strcpy(c.courseName, a);

	c.Class = new char[strlen(className) + 1];
	strcpy(c.Class, className);

	c.lec = new lecture;


	cout << "Lecturer's Name: ";
	cin.ignore(200, '\n');
	cin.get(a, 200, '\n');
	c.lec->name = new char[strlen(a) + 1];
	strcpy(c.lec->name, a);

	cout << "Gender: (1/0): ";
	cin >> c.lec->gender;

	cout << "Start day: ";
	cin >> c.Sdate.day;
	cout << "Start month: ";
	cin >> c.Sdate.month;
	cout << "Start year: ";
	cin >> c.Sdate.year;

	cout << "End day: ";
	cin >> c.Edate.day;
	cout << "End month: ";
	cin >> c.Edate.month;
	cout << "End year: ";
	cin >> c.Edate.year;

	cout << "Day of week: ";
	cin.ignore(200, '\n');
	cin.get(a, 200, '\n');
	c.dayofweek = new char[strlen(a) + 1];
	strcpy(c.dayofweek, a);

	cout << "Start hour: ";
	cin >> c.Stime.hours;
	cout << "Start minute: ";
	cin >> c.Stime.mins;

	cout << "End hour: ";
	cin >> c.Etime.hours;
	cout << "End minute: ";
	cin >> c.Etime.mins;

}

void inputCourse(Schedule& c, char year[], char semester[], char className[], char fileAdd[])
{
	system("cls");
	cout << "=== PLEASE INPUT SOME INFORMATION ===\n";
	char id[20];
	cout << "Course ID: ";
	cin.ignore(200, '\n');
	cin.get(id, 20, '\n');

	int maxno = 0;
	if (isExistCourse(id, year, semester, className, fileAdd, maxno))
    {
		system("cls");
		cout << "The course has already create please try again\n";
		system("pause");
		inputCourse(c, year, semester, className, fileAdd);
	}
	else
    {
		char ad[200] = {};
		strcat(ad, "20/");
		strcat(ad, year);
		strcat(ad, "/");
		strcat(ad, semester);
		strcat(ad, "/");
		strcat(ad, course);
		strcat(ad, "/");
		strcat(ad, id);
		strcat(ad, ".csv");
		ofstream out(ad);

		cin.ignore(100, '\n');
		inputCourseData(c, id, maxno, className);
	}
}

void updateCourseData(Schedule c, char fileAdd[])
{
	ofstream fout(fileAdd, ios::app);
	fout << "\n";
	fout << c.no << "\n";
	fout << c.courseID << "\n";
	fout << c.courseName << "\n";
	fout << c.Class << "\n";
	fout << c.lec->account << "\n";
	fout << c.lec->name << "\n";
	fout << c.lec->gender << "\n";
	fout << c.Sdate.day << "\n";
	fout << c.Sdate.month << "\n";
	fout << c.Sdate.year << "\n";
	fout << c.Edate.day << "\n";
	fout << c.Edate.month << "\n";
	fout << c.Edate.year << "\n";
	fout << c.dayofweek << "\n";
	fout << c.Stime.hours << "\n";
	fout << c.Stime.mins << "\n";
	fout << c.Etime.hours << "\n";
	fout << c.Etime.mins << "\n";
	fout << c.room;
}

bool isExistCourse(char courseID[], char year[], char semester[], char className[], char fileAdd[], int& maxno)
{
	ifstream fin;
	char a[200] = {};
	strcat(a, "20/");
	strcat(a, year);
	strcat(a, "/");
	strcat(a, semester);
	strcat(a, "/");
	strcat(a, course);
	strcat(a, "/Schedule.csv");
	strcpy(fileAdd, a);
	fin.open(fileAdd);
	if (!fin.is_open())
    {
		cout << "ERROR !!!";
		exit(0);
	}
	maxno = countLine(fin, 19);
	fin.close();

	fin.open(fileAdd);
	if (!fin.is_open())
    {
		cout << "ERROR !!!";
		exit(0);
	}
	else
	{
		char a[200];
		while (!fin.eof()) {
			fin.get(a, 200, '\n');
			fin.ignore(200, '\n');
			if (isSameStr(a, courseID))
            {
				fin.close();
				return true;
			}
		}
	}
	fin.close();
	return false;
}

void addANewCourse() {
	//create new variables
	char year[20], semester[20], className[20];
	char fileAdd[500];
	Schedule c;

	//input year semester class
	inputYSC(year, semester, className);

	//input data about the course
	inputCourse(c, year, semester, className, fileAdd);

	//update the data of schedule.txt file
	updateCourseData(c, fileAdd);

	//clean heap memory
	cleanInputCourse(c);
}

