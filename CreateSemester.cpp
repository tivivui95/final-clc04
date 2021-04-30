#include "Header.h"

bool semester_is_exist(Year* &pHead, int &n, char* year, char* semester)
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

void createNewSemester(Year* &pHead, int &n, char* year, char* semester)
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

void deleteSemester(Year* &pHead1)
{
	Year* pCur = pHead1;
	while (pHead1)
    {
		pHead1 = pHead1->pNext;
		delete[] pCur->semestersData;
		delete pCur;
		pCur = pHead1;
	}
}



