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

void showMainMenu()
{
    cout << "\n====================================================\n";
    cout << "     SMART DSA LEARNING AND PROBLEM-SOLVING\n";
    cout << "                  ASSISTANT\n";
    cout << "====================================================\n";
    cout << "1. Student Registration\n";
    cout << "2. Learn DSA Topics\n";
    cout << "3. Practice\n";
    cout << "4. Performance Dashboard\n";
    cout << "5. Data Structure Workbench\n";
    cout << "6. Binary Search Tree\n";
    cout << "7. Recursion Practice\n";
    cout << "8. Learning Recommendations\n";
    cout << "9. Save Student Progress\n";
    cout << "10. Load Student Progress\n";
    cout << "11. Exit\n";
    cout << "----------------------------------------------------\n";
    cout << "Enter your choice: ";
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

    do
    {
        showMainMenu();

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input. Enter a number from 1 to 11: ";
        }

        switch (choice)
        {
        case 1:

            cout << "\n========== STUDENT REGISTRATION ==========\n";

            student.registerStudent();

            break;

        case 2:

            cout << "\n========== DSA LEARNING ==========\n";

            learning.displayTopics();

            break;

        case 3:
        {
            int practiceChoice = 0;

            do
            {
                cout << "\n========================================\n";
                cout << "              PRACTICE\n";
                cout << "========================================\n";
                cout << "1. MCQ Quiz\n";
                cout << "2. Coding Practice\n";
                cout << "3. Back to Main Menu\n";
                cout << "========================================\n";
                cout << "Enter your choice: ";

                while (!(cin >> practiceChoice))
                {
                    cin.clear();
                    cin.ignore(1000, '\n');

                    cout << "Invalid input. Enter 1, 2, or 3: ";
                }

                if (practiceChoice == 1)
                {
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
                    }
                }
                else if (practiceChoice == 2)
                {
                    codingPractice.startPracticeSession();
                }
                else if (practiceChoice == 3)
                {
                    cout << "Returning to main menu...\n";
                }
                else
                {
                    cout << "Invalid choice. Please select 1, 2, or 3.\n";
                }

            } while (practiceChoice != 3);

            break;
        }

        case 4:

            cout << "\n========== PERFORMANCE DASHBOARD ==========\n";

            performance.displayPerformance();

            break;

        case 5:

            cout << "\n========== DATA STRUCTURE WORKBENCH ==========\n";

            linearDS.interactiveMenu();

            break;

        case 6:

            cout << "\n========== BINARY SEARCH TREE ==========\n";

            bst.interactiveMenu();

            break;

        case 7:

            cout << "\n========== RECURSION PRACTICE ==========\n";

            recursion.interactiveMenu();

            break;

        case 8:

            cout << "\n========== LEARNING RECOMMENDATIONS ==========\n";

            recommendation.suggestTopic(
                problemBank.getScore(),
                problemBank.getTotalQuestions(),
                problemBank.hasAttemptedQuiz(),
                performance.getWeakestTopic());

            break;

        case 9:
        {
            if (!student.isRegistered())
            {
                cout << "\nPlease register the student first.\n";
                break;
            }

            if (!problemBank.hasAttemptedQuiz())
            {
                cout << "\nNo quiz performance is available to save.\n";
                cout << "Please attempt the MCQ quiz first.\n";
                break;
            }

            int topicScores[9];
            int topicQuestions[9];

            for (int i = 0; i < 9; i++)
            {
                topicScores[i] =
                    problemBank.getTopicScore(i);

                topicQuestions[i] =
                    problemBank.getTopicQuestions(i);
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

            cout << "\n========== LOAD SAVED PROGRESS ==========\n";

            fileManager.loadProgress();

            break;

        case 11:

            cout << "\nThank you for using Smart DSA Learning "
                    "and Problem-Solving Assistant.\n";

            cout << "Keep learning, practicing and improving!\n";

            break;

        default:

            cout << "\nInvalid choice. Please select 1 to 11.\n";
        }

    } while (choice != 11);

    return 0;
}