#include"Header.h"

void InputScore(Score*& head2, ifstream& Subject_file, ifstream& score_file)
{
    while (!Subject_file.eof())
    {
        Score* t = new Score;
        getline(Subject_file, t->name);
        Subject_file >> t->credit;
        if (head2 == NULL)
            head2 = t;

    }
}

double GPA(int score_earn, int total credit)
{

}
bool Sort(double average_score, double GPA)
{

}
double Average score(int score)
{

}