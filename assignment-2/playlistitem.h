#ifndef PLAYLISTITEM_H
#define PLAYLISTITEM_H

#include <iostream>
#include <string>

#include "song.h"

  /*
   * A PlaylistItem is a "description" of a desired song.
   * It may specify one or more of:  title, artist.
   * If either of these are given as an empty string, this is
   * interpreted to mean that any value in this field will do.
   *
   * For example, if we give an actual title but have "" for
   * the artist, then we would match any song with that title by
   * any artist.
   *
   * All matches should ignore upper/lower case.
   */
struct PlayListItem {
  std::string title;
  std::string artist;
};

bool matches (const PlayListItem& item, const Song& s);

bool read (std::istream& in, PlayListItem& item);



#endif
