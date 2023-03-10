#pragma once
#ifndef DATE_HEADER
#define DATE_HAEDER
#include <assert.h>
#include <iostream>


namespace date {

class Date {
    public:
        Date(int day=1,int mont=1,int year=1000);
        int day() const;
        int month() const;
        int year() const;

        void day(int day);
        void month(int month);
        void year(int year);

    private:
        int _day;
        int _month;
        int _year;

};

bool isDate(int day,int month,int year);
bool isLeap(int year);
bool isNull(const Date& date);
std::ostream& operator<<(std::ostream& os, const Date& dt);

}

#endif