#include "playlistitem.h"
#include "csv.h"

#include <ios>

using namespace std;

/*
 * A PlaylistItem is a "description" of a desired song.
 * It may specify one or more of:  title, artist, album.
 * If any of these are given as an empty string, this is
 * interpreted to mean that any value in this field will do.
 *
 * For example, if we give a title and artist but have "" for
 * the album, then we would match any song with that title by
 * that artist, regardless of which album it is on.
 */

std::string lowercase(const std::string s)
{
    string result = s;
    for (unsigned i = 0; i < result.size(); ++i)
    {
        char c = result[i];
        if (c >= 'A' && c <= 'Z')
            result[i] = c - 'A' + 'a';
    }
    return result;
}

bool matches(const PlayListItem &item, const Song &s)
{
    // cerr << title << "\t" << artist << " : " << s.getTitle() << "\t" << s.getArtist() << endl;
    bool match = true;
    if (item.title.size() > 0)
    {
        match = (lowercase(item.title) == lowercase(s.title));
    }
    if (match && item.artist.size() > 0)
    {
        match = (lowercase(item.artist) == lowercase(s.artist));
    }
    return match;
}

bool read(std::istream &in, PlayListItem &item)
{
    string line;
    if (getline(in, line))
    {
        vector<string> fields = parseCSV(line);
        if (fields.size() == 2)
        {
            item.artist = lowercase(fields[0]);
            item.title = lowercase(fields[1]);
        }
        else
        {
            in.setstate(ios::badbit);
        }
    }
    return (bool)in;
}
