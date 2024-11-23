#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
#include <vector>
#include "playlistitem.h"
#include "song.h"
#include "time.h"


class PlayList {
  std::vector<Song> songs;
  Time totalTime;

public:
    PlayList();

    void add (const Song& song);
    int size() const;
    Time getTotalTime() const;
    std::vector<Song> matchesFor (const PlayListItem& searchKey) const;


    void print (std::ostream& out) const;
    bool read (std::istream& in);
};

std::ostream& operator<< (std::ostream& out, const PlayList& pl);

std::istream& operator>> (std::istream& in, PlayList& pl);


#endif
