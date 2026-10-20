#include <bits/stdc++.h>
#include "../include/Playlist.hpp"
#include "../include/UndoStack.hpp"
#include "../include/PrintQueue.hpp"

using namespace std;

void showMenu() {
    cout << "1. Test Playlist (Linked List)\n";
    cout << "2. Test Browser History (Stack)\n";
    cout << "3. Test Airport Check-in (Queue)\n";
    cout << "0. Exit\n";
    cout << "Seçiminiz: ";
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                Playlist pl;
                pl.addSong(1, "Believer", "Imagine Dragons", 204);
                pl.addSong(2, "STAY", "The Kid LAROI", 141);
                pl.displayPlaylist();
                pl.searchSong(1);
                pl.deleteSong(1);
                pl.displayPlaylist();
                break;
            }
            case 2: {
                UndoStack history;
                history.pushAction(1, "Write Paragraph", "10:00");
                history.pushAction(2, "Insert Image", "10:02");
                history.displayHistory();
                history.undoAction();
                history.currentAction();
                break;
            }
            case 3: {
                PrintQueue queue;
                queue.enqueue(101, "Ali", "AZ-501");
                queue.enqueue(102, "Leyla", "TK-342");
                queue.displayQueue();
                queue.peek();
                queue.dequeue();
                queue.displayQueue();
                break;
            }
            case 0:
                cout << "Proqramdan çixilir...\n";
                break;
            default:
                cout << "Yanliş seçim! Yenidən cəhd edin.\n";
        }
    } while (choice != 0);

    return 0;
}
