#include "../include/PrintQueue.hpp"
#include <bits/stdc++.h>
using namespace std;

PrintQueue::PrintQueue() : front(nullptr), rear(nullptr), count(0) {}

PrintQueue::~PrintQueue() {
    while (front != nullptr) {
        PassengerNode* temp = front;
        front = front->next;
        delete temp;
    }
}

void PrintQueue::enqueue(int id, string name, string flight) {
    PassengerNode* newNode = new PassengerNode(id, name, flight);
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    count++;
    cout << "Passenger added to queue: " << name << "\n";
}

void PrintQueue::dequeue() {
    if (front == nullptr) {
        cout << "Queue is empty (No passengers to check-in).\n";
        return;
    }
    PassengerNode* temp = front;
    cout << "Checked-in successfully: " << temp->name << " (Flight: " << temp->flightNumber << ")\n";
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    count--;
}

void PrintQueue::peek() const {
    if (front == nullptr) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Next Passenger -> ID: " << front->passengerID 
              << ", Name: " << front->name << ", Flight: " << front->flightNumber << "\n";
}

void PrintQueue::displayQueue() const {
    if (front == nullptr) {
        cout << "Queue is empty.\n";
        return;
    }
    PassengerNode* temp = front;
    cout << "CHECK-IN QUEUE (FRONT TO REAR)\n";
    while (temp != nullptr) {
        cout << "ID: " << temp->passengerID << " " << temp->name 
                  << " | Flight: " << temp->flightNumber << "\n";
        temp = temp->next;
    }
}

void PrintQueue::countPassengers() const {
    cout << "Total passengers in queue: " << count << "\n";
}
