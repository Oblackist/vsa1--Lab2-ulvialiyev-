#include <bits/stdc++.h>
#ifndef UNDOSTACK_HPP
#define UNDOSTACK_HPP

using namespace std;


struct ActionNode {
    int actionID;
    string actionName;
    string time;
    ActionNode* next;

    ActionNode(int id, string name, string t)
        : actionID(id), actionName(name), time(t), next(nullptr) {}
};

class UndoStack {
private:
    ActionNode* top;
    int count;

public:
    UndoStack();
    ~UndoStack();

    void pushAction(int id, string name, string time);
    void undoAction();
    void currentAction() const;
    void displayHistory() const;
    void countActions() const;
};

#endif
