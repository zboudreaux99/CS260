#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>
#include "time.h"


struct Song {
  std::string title;
  std::string artist;
  std::string album;
  int track;
  Time length;
};

bool operator==(const Song& left, const Song& right);

std::ostream& operator<< (std::ostream& out, const Song& song);
std::istream& operator>> (std::istream& in, Song& song);


#endif
