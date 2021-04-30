#include "Header.h"

bool semester_is_exist(Year* &pHead, int &n, char* semester, char* year)
{
    char direct[] = "E:\\Data_Bin\\20127261_KTLT\\Final_TH\\final-clc04\\20\\yearData\\";
	char s[500] = "";
	strcat(s, direct);
	strcat(s, year);
	strcat(s, "\\semester.txt");

    ifstream fsin;
    fsin.open(s);

    fsin >> n;
    int check = n;
    if (check == 0)
    {
        fsin.close();
        return false;
    }
    else
    {
        Year* pCur = pHead;
        while (check > 0)
        {
            if (!pHead)
            {
                pHead = new Year();
                char s[12];
                fsin.ignore();
                fsin.get(s, 12, '\n');
                pHead->semestersData = new char[strlen(s) + 1];
                strcpy(pHead->semestersData, s);
                pCur = pHead;
                pHead->pNext = nullptr;
            }
            else
            {
                pCur->pNext = new Year();
                pCur = pCur->pNext;
                char s[12];
                fsin.ignore();
                fsin.get(s, 12, '\n');
                pCur->semestersData = new char[strlen(s) + 1];
                strcpy(pCur->semestersData, s);
                pCur->pNext = nullptr;
            }
            check--;
        }
        fsin.close();

        pCur = pHead;
        while (pCur)
        {
            if (strcmp(pCur->semestersData, semester) == 0) return true;
            pCur = pCur->pNext;

        }
        return false;
    }


}

void createNewSemester(Year* &pHead, int &n, char* semester, char* year)
{
    ofstream fsout;
    fsout.open("E:\\Data_Bin\\20127261_KTLT\\Final_TH\\final-clc04\\20\\yearData\\semester.txt");

    Year* pCur = pHead;
	n += 1;
	fsout << n << endl;
	if (pHead == nullptr)
    {
		pHead = new Year;
		pHead->semestersData = semester;
		pHead->pNext = nullptr;
		fsout << pHead->semestersData;
	}
	else
	{
		while (pCur != nullptr)
        {
			fsout << pCur->semestersData << endl;
			pCur = pCur->pNext;
		}
		pCur = new Year;
		pCur->semestersData = semester;
		fsout << pCur->semestersData;
		pCur->pNext = nullptr;
	}
	fsout.close();

	char direct[] = "20/yearData/";
	char s[500] = "";
	strcat(s, direct);
	strcat(s, year);
	CreateDirectoryA(s, NULL);
	//strcat(s, "/semester.txt");

	fsout.open(s);
	fsout << endl;
	fsout.close();
}

void run1()
{
    Year* pHead = nullptr;
    int n;
    char* year = "2020 - 2021";
    char* sem1 = "Semester 1 (Fall)";
    char* sem2 = "Semester 2 (Summer)";
    char* sem3 = "Semester 3 (Autumn)";
    cout << "Number of semester you want to create: "; cin >> n;
    switch(n)
    {
        case 1:
        {
            cout << "Press '1' for semeseter 1 !" << endl;
            cout << "Press '2' for semeseter 2 !" << endl;
            cout << "Press '3' for semeseter 3 !" << endl;
            int num;
            cout << "Which semester do you want to create ?";
            cin >> num;
            if (num == 1)
            {
                createNewSemester(pHead, n, sem1, year);
            }
            if (num == 2)
            {
                createNewSemester(pHead, n, sem2, year);
            }
            if (num == 3)
            {
                createNewSemester(pHead, n, sem3, year);
            }
        }

        case 2:
        {
            cout << "Press '12' for semeseter 1 and 2 !" << endl;
            cout << "Press '13' for semeseter 1 and 3 !" << endl;
            cout << "Press '23' for semeseter 2 and 3 !" << endl;
            int num;
            cout << "Which semester do you want to create ? ";
            cin >> num;
            if (num == 12)
            {
                createNewSemester(pHead, n, sem1, year);
                createNewSemester(pHead, n, sem2, year);
            }
            if (num == 13)
            {
                createNewSemester(pHead, n, sem1, year);
                createNewSemester(pHead, n, sem3, year);
            }
            if (num == 23)
            {
                createNewSemester(pHead, n, sem2, year);
                createNewSemester(pHead, n, sem3, year);
            }
        }

        case 3:
        {
            createNewSemester(pHead, n, sem1, year);
            createNewSemester(pHead, n, sem2, year);
            createNewSemester(pHead, n, sem3, year);
        }
    }
    //createNewYear(pHead, n, semester, year);
}

int main()
{
    Year* pHead = nullptr;
    int n;
    char* year = "";
    char* semester = "";

    run1();
    cout << "You has created new semester successfully !!!" << endl;
    //year_is_exist(pHead, n, year);
    return 0;
}
