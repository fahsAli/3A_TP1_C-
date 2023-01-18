#include "book.h"


std::string book::Book::title() const{
    return _title;
}

author::Author book::Book::author() const{
    return _author;
}

std::string book::Book::language() const{
    return _language;
}

std::string book::Book::type() const{
    return _type;
}

date::Date book::Book::pubDate() const{
    return _pub_date;
}

std::string book::Book::ISBN() const{
    return _ISBN;
}

bool book::Book::status() const{
    return _status;
}

std::vector <std::string> book::Book::borrowList() const{
    return _borrow_list;
}

void book::Book::title(std::string title){
    _title = title;
}

void book::Book::author(author::Author author){
    _author = author;
}

void book::Book::language(std::string lang){
    _language = lang;
}

void book::Book::type(std::string type){
    _type = type;
}

void book::Book::pubDate(date::Date date){
    _pub_date = date;
}

void book::Book::pubDate(int day,int month,int year){
    _pub_date = date::Date(day,month,year);
}

void book::Book::ISBN(std::string isbn){
    _ISBN = isbn;
}

void book::Book::status(bool stat){
    _status = stat;
}

void book::Book::makeBorrow(std::string id){
    _borrow_list.push_back(id);
}


book::Book::Book(std::string title,author::Author author,std::string lang,std::string type,date::Date pdate,std::string isbn)
:_title(title),_author(author),_language(lang),_type(type),_pub_date(pdate),_ISBN(isbn){
   _borrow_list.resize(0);
   _status=true;
}

std::ostream& book::operator<<(std::ostream& os,const book::Book& b){
    std::string str;
    str = "------------------------\n";
    str = str + "| Title    : " + b.title() + "\n";
    str = str + "| auhtor   : " + b.author().firstName() + " " + b.author().lastName() + "\n";
    str = str + "| pub date : " + std::to_string(b.pubDate().day()) + "/" + std::to_string(b.pubDate().month()) + "/" + std::to_string(b.pubDate().year()) + "\n";
    str = str + "| lang     : " + b.language() + "\n";
    str = str + "| type     : " + b.type() + "\n";
    str = str + "| status   : " + ((b.status()?"available":"borrowed"));
    str = str + "\n";
    os << str;
    return os;
}


