#include "time.h"

using namespace std;


Time::Time()
    : seconds(0)
{}

Time::Time (int h, int m, int s)
{
  seconds = s + 60 * (m + 60*h);
  if (seconds < 0)
    seconds = 0;
}

int Time::getHours() const
{
  return seconds / 3600;
}


int Time::getMinutes() const
{
  return seconds / 60 - 60*getHours();
}


int Time::getSeconds() const
{
  return seconds % 60;
}


void Time::add (Time right)
{
  seconds +=  right.seconds;
}


void Time::subtract (Time right)
{
  seconds  -= right.seconds;
  if (seconds < 0)
    seconds = 0;
}
  


bool Time::read (std::istream& in)
{
  int h = 0;
  int m = 0;
  int s = 0;
  if (!(in >> m)) return !in.fail();
  char c;
  in.get(c);
  if (!(in >> s) || c != ':') return !in.fail();
  c = in.peek();
  in.clear();
  if (c == ':')
    {
      in.get(c);
      h = m;
      m = s;
      if (!(in >> s)) return !in.fail();
    }
  seconds = s + 60 * (m + 60*h);
  return true;
}


void Time::print (std::ostream& out) const
{
  int h = getHours();
  if (h > 0)
    {
      if (h < 10)
	out << '0';
      out << h << ":";
    }
  int m = getMinutes();
  if (m < 10)
    out << '0';
  out << m << ":";
  int s = getSeconds();
  if (s < 10)
    out << '0';
  out << s;
}

bool Time::operator== (const Time& right) const
{
    return seconds == right.seconds;
}

std::ostream& operator<<(std::ostream &out, const Time &time) {
    time.print(out);
    return out;
}

std::istream& operator>>(std::istream &in, Time &time)
{
    time.read(in);
    return in;
}
