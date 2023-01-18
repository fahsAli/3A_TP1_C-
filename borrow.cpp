#include "borrow.h"

date::Date borrow::Borrow::borrowDate() const{
    return _borrow_date;
}

std::string borrow::Borrow::ISBN() const{
    return _ISBN;
}

reader::Reader borrow::Borrow::reader() const{
    return _reader;
}

bool borrow::Borrow::validBorrow() const{
    return _valid_borrow;
}

void borrow::Borrow::borrowDate(date::Date date){
    _borrow_date = date;
}

void borrow::Borrow::ISBN(std::string isbn){
    _ISBN = isbn; 
}

void borrow::Borrow::reader(reader::Reader reader){
    _reader = reader;
}

void borrow::Borrow::validBorrow(bool valid){
    _valid_borrow = valid;
}

bool borrow::Borrow::isNull(){
    return ((date::isNull(_borrow_date))||(_reader.isNull())||(_ISBN == "000000"));
}

void borrow::addISBN(reader::Reader& reader,std::string isbn){
    reader.addisbn(isbn);
}

void borrow::removeISBN(reader::Reader& reader,std::string isbn){
    reader.removeisbn(isbn);
}

borrow::Borrow::Borrow(reader::Reader& reader,std::string isbn, date::Date date)
:_borrow_date(date),_ISBN(isbn),_reader(reader){
    if(!this->isNull()){
        borrow::addISBN(_reader,isbn);
        _valid_borrow = true;
    }else{
        _valid_borrow = false;
    }
}

std::ostream& borrow::operator<<(std::ostream& os,const borrow::Borrow& b){
    std::string str;
    str = " - isbn : " + b.ISBN() + " is borrowed by : ";
    str = str + b.reader().getFullName() + "\n";
    os << str;
    return os;
}



