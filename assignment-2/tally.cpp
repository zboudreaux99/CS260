/*
 * Usage:  tally songsList.csv playlist.csv
 */

#include "playlist.h"
#include "playlistitem.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cerr << "Usage: " << argv[0] << " songsList.csv playlist.csv" << endl;
        return -1;
    }
    PlayList allSongs;
    ifstream songsIn(argv[1]);
    songsIn >> allSongs;
    cout << "Read " << allSongs.size() << " songs." << endl;

    PlayList playlist;
    ifstream selectionsIn(argv[2]);
    PlayListItem item;
    int itemCount = 0;
    while (read(selectionsIn, item))
    {
        ++itemCount;
        vector<Song> selections = allSongs.matchesFor(item);
        for (unsigned i = 0; i < selections.size(); ++i)
        {
            playlist.add(selections[i]);
        }
    }
    cout << "Processed " << itemCount << " playlist items.\n"
         << endl;
    cout << playlist << endl;
    return 0;
}
