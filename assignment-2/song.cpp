#include "song.h"
#include "csv.h"
#include <sstream>
#include <vector>

using namespace std;

std::istream &operator>>(std::istream &in, Song &song)
{
    string line;
    getline(in, line);
    if (in.fail())
        return in;
    vector<string> fields = parseCSV(line);
    if (fields.size() != 5)
    {
        in.setstate(ios::badbit);
        return in;
    }
    song.artist = fields[0];
    song.album = fields[1];
    {
        string trackStr = fields[2];
        istringstream trackIn(trackStr);
        if (!(trackIn >> song.track))
        {
            in.setstate(ios::badbit);
            return in;
        }
    }
    song.title = fields[3];
    {
        string timeStr = fields[4];
        istringstream timeIn(timeStr);
        if (!(timeIn >> song.length))
        {
            in.setstate(ios::badbit);
            return in;
        }
    }
    return in;
}

std::string pad(int width, const std::string s)
{
    string r = s + string(width, ' ');
    return r.substr(0, width);
}

std::ostream &operator<<(std::ostream &out, const Song &song)
{
    out << pad(24, song.title) << ' '
        << pad(19, song.artist) << ' '
        << pad(24, song.album) << ' '
        << song.track << ' '
        << song.length;
    return out;
}

bool operator==(const Song &left, const Song &right)
{
    return left.title == right.title && left.artist == right.artist && left.album == right.album && left.track == right.track && left.length == right.length;
}
