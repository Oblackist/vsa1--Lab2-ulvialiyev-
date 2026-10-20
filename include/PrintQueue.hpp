#include <bits/stdc++.h>
#ifndef PRINTQUEUE_HPP
#define PRINTQUEUE_HPP

using namespace std;


struct PassengerNode {
    int passengerID;
    string name;
    string flightNumber;
    PassengerNode* next;

    PassengerNode(int id, string n, string flight)
        : passengerID(id), name(n), flightNumber(flight), next(nullptr) {}
};

class PrintQueue {
private:
    PassengerNode* front;
    PassengerNode* rear;
    int count;

public:
    PrintQueue();
    ~PrintQueue();

    void enqueue(int id, string name, string flight);
    void dequeue();
    void peek() const;
    void displayQueue() const;
    void countPassengers() const;
};

#endif
