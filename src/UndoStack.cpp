#include "../include/UndoStack.hpp"
#include <bits/stdc++.h>

using namespace std;

UndoStack::UndoStack() : top(nullptr), count(0) {}

UndoStack::~UndoStack() {
    while (top != nullptr) {
        ActionNode* temp = top;
        top = top->next;
        delete temp;
    }
}

void UndoStack::pushAction(int id, string name, string time) {
    ActionNode* newNode = new ActionNode(id, name, time);
    newNode->next = top;
    top = newNode;
    count++;
    cout << "Action performed: " << name << "\n";
}

void UndoStack::undoAction() {
    if (!top) {
        cout << "No actions to undo (Stack is empty).\n";
        return;
    }
    ActionNode* temp = top;
    cout << "Undo: " << temp->actionName << "\n";
    top = top->next;
    delete temp;
    count--;
}

void UndoStack::currentAction() const {
    if (!top) {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Current (Top) Action -> ID: " << top->actionID 
              << ", Name: " << top->actionName << ", Time: " << top->time << "\n";
}

void UndoStack::displayHistory() const {
    if (!top) {
        cout << "History is empty.\n";
        return;
    }
    ActionNode* temp = top;
    cout << "BROWSER HISTORY (STACK: TOP TO BOTTOM)\n";
    while (temp != nullptr) {
        cout << "[ID: " << temp->actionID << "] " << temp->actionName 
                  << " at " << temp->time << "\n";
        temp = temp->next;
    }
}

void UndoStack::countActions() const {
    cout << "Total actions in history: " << count << "\n";
}
