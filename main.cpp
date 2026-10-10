#include <iostream>
#include "student.hpp"
#include "learning.hpp"
#include "problembank.hpp"
#include "performance.hpp"
#include "linearDS.hpp"
#include "FileManager.hpp"
#include "recommendation.hpp"

using namespace std;

void showMenu()
{
    cout << "\n ^_^ Smart DSA Learning And Problem Solving Assistant ^_^ \n";
    cout << " PRESS  1 : FOR STUDENT REGISTRATION\n";
    cout << " PRESS  2 : FOR LEARNING DSA TOPICS\n";
    cout << " PRESS  3 : FOR PRACTICING QUESTIONS\n";
    cout << " PRESS  4 : FOR VIEWING YOUR PERFORMANCE\n";
    cout << " PRESS  5 : FOR LEARNING LINEAR DATA STRUCTURES\n";
    cout << " PRESS  6 : FOR RECOMMENDATION OF WEAK TOPICS\n";
    cout << " PRESS  7 : FOR SAVING STUDENT PROGRESS\n";
    cout << " PRESS  8 : FOR LOADING STUDENT PROGRESS\n";
    cout << " PRESS  9 : FOR RECOMMENDING WEAK TOPICS\n";
    cout << " PRESS 10 : FOR EXITING.... \n";

    cout << "EnTeR yOuR cHoIcE => ";
}

int main()
{
    Student s;
    Learning l;
    ProblemBank p;
    Performance perf;
    LinearDS ds;
    FileManager fm;
    Recommendation r;

    int choice = 0;

    do
    {
        showMenu();

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << " -_- !! InVaLiD iNpUt !! -_- \n";
            continue;
        }

        switch (choice)
        {
        case 1:
            cout << "\nSTUDENT REGISTRATION SELECTED\n";
            s.registerStudent();
            break;

        case 2:
            cout << "\nDSA LEARNING MODULE SELECTED\n";
            l.displayTopics();
            break;

        case 3:
            cout << "\nPRACTICE QUESTIONS SELECTED\n";
            p.startQuiz();
            perf.setPerformance(p.getScore(), p.getTotalQuestions());
            break;

        case 4:
            cout << "\nPERFORMANCE MODULE SELECTED\n";
            perf.displayPerformance();
            break;

        case 5:
            cout << "\nLinear Data Structures\n";
            ds.interactiveMenu();
            break;

        case 6:
            cout << "\nRECOMMENDATION MODULE SELECTED\n";
            r.suggestTopic(p.getScore(), p.getTotalQuestions(), p.hasAttemptedQuiz());
            break;

        case 7:
            if (s.isRegistered())
            {
                fm.saveProgress(
                    s.getStudentID(),
                    s.getStudentName(),
                    p.getScore(),
                    p.getTotalQuestions());
            }
            else
            {
                cout << "Please register first!\n";
            }
            break;

        case 8:
            fm.loadProgress();
            break;

        case 9:
            cout << "\nRECOMMENDATION MODULE SELECTED\n";
            r.suggestTopic(p.getScore(), p.getTotalQuestions(), p.hasAttemptedQuiz());
            break;

        case 10:
            cout << "\n^_^ ThAnKu FoR uSiNg OuR aSsIsTaNt ^_^\n";
            break;

        default:
            cout << " -_- !! InVaLiD cHoIcE !! -_- \n";
        }

    } while (choice != 10);

    return 0;
}