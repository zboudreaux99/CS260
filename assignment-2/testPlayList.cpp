#include "playlist.h"
#include "time.h"
#include "unittest.h"
#include <sstream>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

PlayListItem bandOnly {"", "The Who"};
PlayListItem titleOnly {"Who are You?", ""};
PlayListItem bandAndTitle {"who are You?", "the who"};
PlayListItem pfBand {"", "Pink Floyd"};

Song who1 {"Love is Coming Down","The Who","Who Are You",8,Time(0, 4, 2)};
Song who2 {"Who Are You?","The Who","Who Are You",9, Time(0, 6, 24)};
Song pf {"The Great Gig In The Sky","Pink Floyd","Dark Side Of The Moon",4, Time(0, 4, 49)};



UnitTest(Constructor) {
	PlayList pl;
	assertThat (pl.size(), is(0));
    assertThat(pl.getTotalTime(), is(Time(0,0,0)));

    vector<Song> matches = pl.matchesFor(bandAndTitle);
    assertThat(matches.size(), is(0));
}

UnitTest(Add1) {
	PlayList pl;
    pl.add(who2);
	assertThat (pl.size(), is(1));
    assertThat(pl.getTotalTime(), is(Time(0, 6, 24)));

    vector<Song> matches = pl.matchesFor(bandAndTitle);
    assertThat(matches.size(), is(1));
    assertThat(matches[0], is(who2));

    matches = pl.matchesFor(bandOnly);
    assertThat(matches.size(), is(1));
    assertThat(matches[0], is(who2));

    matches = pl.matchesFor(titleOnly);
    assertThat(matches.size(), is(1));
    assertThat(matches[0], is(who2));

    matches = pl.matchesFor(pfBand);
    assertThat(matches.size(), is(0));
}

UnitTest(AddMulti) {
	PlayList pl;
    pl.add(who1);
    pl.add(who2);
    pl.add(pf);

	assertThat (pl.size(), is(3));
    assertThat(pl.getTotalTime(), is(Time(0, 15, 15)));

    vector<Song> matches = pl.matchesFor(bandAndTitle);
    assertThat(matches.size(), is(1));
    assertThat(matches[0], is(who2));

    matches = pl.matchesFor(bandOnly);
    assertThat(matches.size(), is(2));
    assertThat(matches, contains(who1));
    assertThat(matches, contains(who2));

    matches = pl.matchesFor(titleOnly);
    assertThat(matches.size(), is(1));
    assertThat(matches[0], is(who2));

    matches = pl.matchesFor(pfBand);
    assertThat(matches.size(), is(1));
    assertThat(matches[0], is(pf));

}
