#pragma once

class Learning
{
public:
    void displayTopics();
    void showTopicDetails(int choice);

private:
    void explainArrays();
    void explainStrings();
    void explainSearching();
    void explainSorting();
    void explainLinkedLists();
    void explainStacks();
    void explainQueues();
    void explainCircularQueue();
    void explainPriorityQueue();
    void explainBST();
    void explainRecursion();

    void showResources(
        const char *video,
        const char *reading,
        const char *practice);
};