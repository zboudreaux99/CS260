#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time
{
    int seconds;

public:
    Time(int h, int m, int s);

    Time();

    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    void add(Time right);
    void subtract(Time right);

    bool read(std::istream &in);
    void print(std::ostream &out) const;

    bool operator==(const Time& right) const;
};

std::ostream& operator<<(std::ostream &out, const Time &time);

std::istream& operator>>(std::istream &in, Time &time);

#endif
