#include "Header.h"


bool year_is_exist(Year* &pHead, int& n, char* year)
{
    ifstream fyear;
    fyear.open("E:\\Data_Bin\\20127261_KTLT\\\Final_TH\\\final-clc04\\20\\yearData");
    fyear >> n;
    int check = n;
    if (check == 0)
    {
        fyear.close();
        return false;
    }
    else
    {
        Year* pCur = pHead;
        while (check > 0)
        {
            if (pHead == nullptr)
            {
                pHead = new Year();
                char c[12];
                fyear.ignore();
                fyear.get(c, 12, '\n');
                pHead->yearsData = new char[strlen(c) + 1];
                strcpy(pHead->yearsData, c);
                pCur = pHead;
                pHead->pNext = nullptr;
            }
            else
            {
                pCur->pNext = new Year();
                pCur = pCur->pNext;
                char c[12];
                fyear.ignore();
                fyear.get(c, 12, '\n');
                pCur->yearsData = new char[strlen(c) + 1];
                strcpy(pCur->yearsData, c);
                pCur->pNext = nullptr;
            }
            check--;
        }
        fyear.close();
        pCur = pHead;
        while (pCur)
        {
            if (strcmp(pCur->yearsData, year) == 0)
            {
                return true;
            }
            pCur = pCur->pNext;
        }
        return false;
    }
}

void createNewYear(Year* &pHead, int n, char* year)
{
    ofstream fyear;
    fyear.open("20/yearData/year.txt");

    Year* pCur = pHead;
    fyear << n << endl;
    if (pHead == nullptr)
    {
        pHead = new Year();
        pHead->yearsData = year;
        pHead->pNext = nullptr;
        fyear << pHead->yearsData;
    }
    else
    {
        while (pCur)
        {
            fyear << pCur->yearsData << endl;
            pCur = pCur->pNext;
        }
        pCur = new Year();
        pCur->yearsData = year;
        fyear << pCur->yearsData;
        pCur->pNext = nullptr;
    }
    fyear.close();

    char direct[] = "20/yearData/";
	char y[500] = "";
	strcat(y, direct);
	strcat(y, year);
	CreateDirectoryA(y, NULL);
	strcat(y, "/semester.txt");

	fyear.open(y);
	fyear << endl;
	fyear.close();
}

void deleteYear(Year*& pHead)
{
	Year* pCur = pHead;
	while (pHead)
    {
		pHead = pHead->pNext;
		delete[] pCur->yearsData;
		delete pCur;
		pCur = pHead;
	}
}

