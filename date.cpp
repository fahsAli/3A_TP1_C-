#include "date.h"


bool date::isLeap(int year){
    return (((year & 3) == 0) &&(((year % 100) != 0)||((year % 400)==0)));
}


bool date::isDate(int day,int month,int year){
    if ((day < 1) || (day>31)) return false;
    if ((month <1) || (month>12)) return false;

    if ((month == 2) && (day > 28) && (!isLeap(year))) return false;
    if ((month == 2) && (day > 29) && isLeap(year)) return false;
    if (((month == 4) || (month == 6) ||
        (month == 9) || (month == 11)) && (day > 30)) return false;
    return true;
}

int date::Date::day() const{
    return _day;
}

int date::Date::month() const{
    return _month;
}

int date::Date::year() const{
    return _year;
}

void date::Date::day(int day){
    if(isDate(day,_month,_year)){
        _day = day;
    }
}

void date::Date::month(int month){
    if(isDate(_month,month,_year)){
        _month = month;
    }
}

void date::Date::year(int year){
    if(isDate(_day,_month,year)){
        _year = year;
    }
}

bool date::isNull(const date::Date& date){
    return (date.year()==1000);
}

std::ostream& date::operator<<(std::ostream& os, const date::Date& dt){
    os << std::to_string(dt.day()) << "/" << std::to_string(dt.month()) << "/" << std::to_string(dt.year()) << "\n";
    return os;
}

date::Date::Date(int day,int month,int year)
:_day(day),_month(month),_year(year){
    bool status = isDate(day,month,year);
    assert(status && "Date is not valid");
}

