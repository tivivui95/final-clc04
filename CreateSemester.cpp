#include "Header.h"

void createNewSemester(Year* &pHead, int &n, char* semester, char* year)
{
    ofstream fsout;
    fsout.open("E:\\Data_Bin\\20127261_KTLT\\Final_TH\\final-clc04\\20\\yearData\\semester.txt");

    Year* pCur = pHead;
	n += 1;
	fout << n << endl;
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
			fout << pCur->semestersData << endl;
			pCur = pCur->pNext;
		}
		pCur = new Year;
		pCur->semestersData = semester;
		fsout << pCur->semestersData;
		pCur->pNext = nullptr;
	}
	fsout.close();
}
