#include "../include/Playlist.hpp"
#include <bits/stdc++.h>
using namespace std;

Playlist::Playlist() : head(nullptr), count(0) {}

Playlist::~Playlist() {
    SongNode* current = head;
    while (current != nullptr) {
        SongNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void Playlist::addSong(int id, std::string name, std::string art, int dur) {
    SongNode* newNode = new SongNode(id, name, art, dur);
    if (!head) {
        head = newNode;
    } else {
        SongNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    count++;
    cout << "Song added successfully: " << name << "\n";
}

void Playlist::deleteSong(int id) {
    if (!head) {
        cout << "Playlist is empty!\n";
        return;
    }

    if (head->songID == id) {
        SongNode* temp = head;
        head = head->next;
        delete temp;
        count--;
        cout << "Song with ID " << id << " deleted successfully.\n";
        return;
    }

    SongNode* current = head;
    while (current->next != nullptr && current->next->songID != id) {
        current = current->next;
    }

    if (current->next == nullptr) {
        cout << "Song with ID " << id << " not found.\n";
    } else {
        SongNode* temp = current->next;
        current->next = current->next->next;
        delete temp;
        count--;
        cout << "Song with ID " << id << " deleted successfully.\n";
    }
}

void Playlist::searchSong(int id) {
    SongNode* temp = head;
    while (temp != nullptr) {
        if (temp->songID == id) {
            cout << "Found -> ID: " << temp->songID << ", Name: " << temp->songName 
                      << ", Artist: " << temp->artist << ", Duration: " << temp->duration << "s\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Song with ID " << id << " not found.\n";
}

void Playlist::displayPlaylist() const {
    if (!head) {
        cout << "Playlist is empty.\n";
        return;
    }
    SongNode* temp = head;
    cout << "--- CURRENT PLAYLIST ---\n";
    while (temp != nullptr) {
        cout << "[ID: " << temp->songID << "] " << temp->songName 
                  << " - " << temp->artist << " (" << temp->duration << "s)\n";
        temp = temp->next;
    }
}

void Playlist::countSongs() const {
    cout << "Total songs in playlist: " << count << "\n";
}

void Playlist::playNextSong() {
    if (!head) {
        cout << "No songs to play.\n";
        return;
    }
    cout << "Now playing: " << head->songName << " by " << head->artist << "\n";
    
}
