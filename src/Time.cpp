#include <iostream>
#include "../include/Time.h"
using namespace std;

// Overload the + operator
Time Time::operator+(const Time &other) const
{   
    int minutesTotal = this->minutes + other.minutes;
    int hoursTotal = this->hours + other.hours + ( minutesTotal / 60 );
    minutesTotal &= 60;
    return Time( hoursTotal, minutesTotal);

}

// Overload the += operator
Time& Time::operator+=(const Time &other)
{   
    this->minutes += other.minutes;
    this->hours += other.hours + (this->minutes / 60 );
    this->minutes &= 60;
    return(*this);



}

// Overload the < operator
bool Time::operator<(const Time &other) const
{
    if ( ( this->minutes + ( this->hours * 60) ) < ( other.minutes + ( other.hours * 60) ) ) {return true};
    return false;
}

// Overload the > operator
bool Time::operator>(const Time &other) const
{
    if ( ( this->minutes + ( this->hours * 60) ) > ( other.minutes + ( other.hours * 60) ) ) {return true};
    return false;
}

// Overload the == operator
bool Time::operator==(const Time &other) const
{
    if ( ( this->minutes + ( this->hours * 60) ) == ( other.minutes + ( other.hours * 60) ) ) {return true};
    return false;
}

// Overload the friend function operator<<
ostream &operator<<(ostream &os, const Time &tm)
{
    os << tm.getHours() << ":" << tm.getMinutes();
    return os; 
}
