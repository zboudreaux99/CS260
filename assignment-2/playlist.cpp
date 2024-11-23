#include <iostream>
#include <string>
#include <vector>
#include "playlist.h"
#include "song.h"

using namespace std;

PlayList::PlayList()
    : totalTime(0,0,0)
{
}

int PlayList::size() const
{
    return songs.size();
}

Time PlayList::getTotalTime() const
{
    return totalTime;
}

void PlayList::add(const Song &song)
{
    songs.push_back(song);
    totalTime.add(song.length);
}

std::vector<Song> PlayList::matchesFor(const PlayListItem &searchKey) const
{
    vector<Song> results;
    for (unsigned i = 0; i < songs.size(); ++i)
    {
        if (matches(searchKey, songs[i]))
        {
            results.push_back(songs[i]);
        }
    }
    return results;
}

void PlayList::print(std::ostream &out) const
{
    for (unsigned i = 0; i < songs.size(); ++i)
    {
        out << songs[i] << endl;
    }
    out << "Total: " << totalTime << endl;
}

bool PlayList::read(std::istream &in)
{
    songs.clear();
    totalTime = Time(0, 0, 0);
    Song s;
    while (in >> s)
    {
        add(s);
    }
    return !in.fail();
}

std::ostream& operator<< (std::ostream& out, const PlayList& pl) {
    pl.print(out);
    return out;
}

std::istream& operator>> (std::istream& in, PlayList& pl) {
    pl.read(in);
    return in;
}
