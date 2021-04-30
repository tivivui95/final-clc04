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

