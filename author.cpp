#include "author.h"


std::string author::Author::firstName() const {
    return _fname;
}

std::string author::Author::lastName() const {
    return _lname;
}

std::string author::Author::id() const{
    return _id;
}

date::Date author::Author::bdate() const{
    return _bdate;
}

void author::Author::firstName(std::string fname){
    _fname = fname;
}

void author::Author::lastName(std::string lname){
    _lname = lname;
}

void author::Author::bdate(int day,int month,int year){
    _bdate.day(day);
    _bdate.month(month);
    _bdate.year(year);

}

void author::Author::bdate(date::Date d){
    _bdate = d;
}

bool author::Author::isNull() const{
    return ((_fname == "null")||(_lname == "null"));
}

author::Author::Author(std::string fname,std::string lname,date::Date date)
:_fname(fname),_lname(lname),_bdate(date){
    
    if(!this->isNull()){ 
        _id = fname[0]+lname;
    }else{
        _id = "null";}
        
}

std::ostream& author::operator<<(std::ostream& os,const author::Author aut)
{
    std::string str;

    if(aut.isNull()){
        str = "not defined\n";
    }else{
        str = aut.firstName() + " " + aut.lastName() + "\n";
    }

    os << str;
    return os;
}

bool author::operator==(const author::Author aut1, const author::Author aut2){
    return (aut1.firstName()==aut2.firstName())&&(aut1.lastName()==aut2.lastName());
}