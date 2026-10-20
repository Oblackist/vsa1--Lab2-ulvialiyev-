#include <bits/stdc++.h>
#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

using namespace std;


struct SongNode {
    int songID;
    std::string songName;
    std::string artist;
    int duration;
    SongNode* next;

    SongNode(int id, string name, string art, int dur)
        : songID(id), songName(name), artist(art), duration(dur), next(nullptr) {}
};

class Playlist {
private:
    SongNode* head;
    int count;

public:
    Playlist();
    ~Playlist();

    void addSong(int id, string name, string art, int dur);
    void deleteSong(int id);
    void searchSong(int id);
    void displayPlaylist() const;
    void countSongs() const;
    void playNextSong();
};

#endif
