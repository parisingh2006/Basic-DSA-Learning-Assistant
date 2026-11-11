#include <iostream>

#include "student.hpp"
#include "learning.hpp"
#include "problembank.hpp"
#include "performance.hpp"
#include "linearDS.hpp"
#include "FileManager.hpp"
#include "recommendation.hpp"
#include "codingpractice.hpp"
#include "BST.hpp"
#include "Recursion.hpp"

using namespace std;

void showWelcomeScreen()
{
    cout << "\n";
    cout << "============================================================\n";
    cout << "              SMART DSA LEARNING ASSISTANT                  \n";
    cout << "============================================================\n";
    cout << "\n";
    cout << "        Learn  |  Practice  |  Analyze  |  Improve\n";
    cout << "\n";
    cout << "        +------------------------------------------+\n";
    cout << "        |       DATA STRUCTURES & ALGORITHMS       |\n";
    cout << "        |          SEMESTER 3 PBL PROJECT          |\n";
    cout << "        +------------------------------------------+\n";
    cout << "\n";
    cout << "              Welcome to your DSA learning space!\n";
    cout << "============================================================\n";
}

void showSectionHeader(const char *title)
{
    cout << "\n";
    cout << "============================================================\n";
    cout << "                    " << title << "\n";
    cout << "============================================================\n";
}

void showMainMenu(Student &student)
{
    cout << "\n";
    cout << "+----------------------------------------------------------+\n";
    cout << "|                     MAIN MENU                            |\n";
    cout << "+----------------------------------------------------------+\n";

    if (student.isRegistered())
    {
        cout << "| Student: " << student.getStudentName() << "\n";
        cout << "| ID     : " << student.getStudentID() << "\n";
    }
    else
    {
        cout << "| Student: Not registered\n";
    }

    cout << "+----------------------------------------------------------+\n";
    cout << "|                                                          |\n";
    cout << "|  [1]  Student Registration                               |\n";
    cout << "|  [2]  Learn DSA Topics                                   |\n";
    cout << "|  [3]  Practice                                           |\n";
    cout << "|  [4]  Performance Dashboard                              |\n";
    cout << "|  [5]  Data Structure Workbench                           |\n";
    cout << "|  [6]  Binary Search Tree                                 |\n";
    cout << "|  [7]  Recursion Practice                                 |\n";
    cout << "|  [8]  Learning Recommendations                           |\n";
    cout << "|  [9]  Save Student Progress                              |\n";
    cout << "|  [10] Load Student Progress                              |\n";
    cout << "|  [11] Exit                                               |\n";
    cout << "|                                                          |\n";
    cout << "+----------------------------------------------------------+\n";
    cout << " Enter your choice: ";
}

int main()
{
    Student student;
    Learning learning;
    ProblemBank problemBank;
    Performance performance;
    LinearDS linearDS;
    FileManager fileManager;
    Recommendation recommendation;
    CodingPractice codingPractice;
    BST bst;
    Recursion recursion;

    int choice = 0;

    showWelcomeScreen();

    do
    {
        showMainMenu(student);

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << " Invalid input. Enter a number from 1 to 11: ";
        }

        switch (choice)
        {
        case 1:
            showSectionHeader("STUDENT REGISTRATION");

            student.registerStudent();

            cout << "\n Student profile is ready.\n";
            break;

        case 2:
            showSectionHeader("DSA LEARNING");

            learning.displayTopics();
            break;

        case 3:
        {
            int practiceChoice = 0;

            do
            {
                cout << "\n";
                cout << "+------------------------------------------+\n";
                cout << "|                 PRACTICE                 |\n";
                cout << "+------------------------------------------+\n";
                cout << "|  1. MCQ Quiz                             |\n";
                cout << "|  2. Coding Practice                      |\n";
                cout << "|  3. Back to Main Menu                    |\n";
                cout << "+------------------------------------------+\n";
                cout << " Enter your choice: ";

                while (!(cin >> practiceChoice))
                {
                    cin.clear();
                    cin.ignore(1000, '\n');

                    cout << " Invalid input. Enter 1, 2, or 3: ";
                }

                if (practiceChoice == 1)
                {
                    showSectionHeader("MCQ QUIZ");

                    problemBank.startQuiz();

                    if (problemBank.hasAttemptedQuiz())
                    {
                        performance.setPerformance(
                            problemBank.getScore(),
                            problemBank.getTotalQuestions());

                        for (int i = 0; i < 9; i++)
                        {
                            performance.setTopicPerformance(
                                i,
                                problemBank.getTopicScore(i),
                                problemBank.getTopicQuestions(i));
                        }

                        cout << "\n Quiz performance updated successfully.\n";
                    }
                }
                else if (practiceChoice == 2)
                {
                    showSectionHeader("CODING PRACTICE");

                    codingPractice.startPracticeSession();
                }
                else if (practiceChoice == 3)
                {
                    cout << "\n Returning to main menu...\n";
                }
                else
                {
                    cout << "\n Invalid choice. Select 1, 2, or 3.\n";
                }

            } while (practiceChoice != 3);

            break;
        }

        case 4:
            showSectionHeader("PERFORMANCE DASHBOARD");

            performance.displayPerformance();
            break;

        case 5:
            showSectionHeader("DATA STRUCTURE WORKBENCH");

            linearDS.interactiveMenu();
            break;

        case 6:
            showSectionHeader("BINARY SEARCH TREE");

            bst.interactiveMenu();
            break;

        case 7:
            showSectionHeader("RECURSION PRACTICE");

            recursion.interactiveMenu();
            break;

        case 8:
            showSectionHeader("LEARNING RECOMMENDATIONS");

            recommendation.suggestTopic(
                problemBank.getScore(),
                problemBank.getTotalQuestions(),
                problemBank.hasAttemptedQuiz(),
                performance.getWeakestTopic());
            break;

        case 9:
        {
            showSectionHeader("SAVE STUDENT PROGRESS");

            if (!student.isRegistered())
            {
                cout << " Please register the student first.\n";
                break;
            }

            if (!problemBank.hasAttemptedQuiz())
            {
                cout << " No quiz performance is available to save.\n";
                cout << " Please attempt the MCQ quiz first.\n";
                break;
            }

            int topicScores[9];
            int topicQuestions[9];

            for (int i = 0; i < 9; i++)
            {
                topicScores[i] = problemBank.getTopicScore(i);
                topicQuestions[i] = problemBank.getTopicQuestions(i);
            }

            fileManager.saveProgress(
                student.getStudentID(),
                student.getStudentName(),
                problemBank.getScore(),
                problemBank.getTotalQuestions(),
                topicScores,
                topicQuestions);

            break;
        }

        case 10:
            showSectionHeader("LOAD SAVED PROGRESS");

            fileManager.loadProgress();
            break;

        case 11:
            cout << "\n";
            cout << "============================================================\n";
            cout << "              THANK YOU FOR LEARNING WITH US!              \n";
            cout << "============================================================\n";
            cout << "\n";
            cout << "        Learn  ->  Practice  ->  Analyze  ->  Improve\n";
            cout << "\n";
            cout << "              Keep coding. Keep improving.\n";
            cout << "============================================================\n";
            cout << "\n";
            break;

        default:
            cout << "\n Invalid choice. Please select 1 to 11.\n";
        }

    } while (choice != 11);

    return 0;
}