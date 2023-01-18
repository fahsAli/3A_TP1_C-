#include "reader.h"



bool reader::Reader::isNull() const{
    return((_fname == "null")||(_lname == "null"));
}

std::string reader::Reader::id() const{
    return _id;
}

std::string reader::Reader::firstName() const{
    return _fname;
}

std::string reader::Reader::lastName() const{
    return _lname;
}

std::vector <std::string> reader::Reader::ISBN_list() const{
    return _ISBN_list;
}

std::string reader::Reader::getFullName() const{
    return _fname + " " + _lname;
}

int reader::Reader::borrowedBooksNumber() const{
    return _borrowed_books_number;
}

void reader::Reader::id(std::string id){
    _id = id;
}

void reader::Reader::lastName(std::string lname){
    _lname = lname;
}

void reader::Reader::firstName(std::string fname){
    _fname = fname;
}

void reader::Reader::addisbn(std::string isbn){
    _ISBN_list.push_back(isbn);
    _borrowed_books_number++;
}

void reader::Reader::removeisbn(std::string isbn){
    auto it_end = std::remove(_ISBN_list.begin(),_ISBN_list.end(), isbn);
    _ISBN_list.erase(it_end, _ISBN_list.end());
}

reader::Reader::Reader(std::string fname,std::string lname)
:_fname(fname),_lname(lname){
    _id = fname[0]+lname;
    _ISBN_list.resize(0);
    _borrowed_books_number=0;
}


std::ostream& reader::operator<<(std::ostream& os,const reader::Reader& read){
    std::string str;
    if(read.isNull()){
        str = "not defined";
    }else{
        str = read.firstName() + " " + read.lastName() + "(BB : " + std::to_string(read.borrowedBooksNumber()) + ")";
    }
    os << str+"\n";
    return os;
}

std::ostream& operator << (std::ostream&os,std::vector <std::string>  v){
    std::string str = "[ ";
    int j=1;
    if(!v.empty()){
        for(auto i=v.begin();i!=v.end()-1;++i){
            str = str + "(" + std::to_string(j) +"): " + *i + " , ";
            j++;
        }
        str = str + "(" + std::to_string(j) + "): " + *(v.end()-1);
    }else{
        str = str + " empty ";
    }
    str = str + " ]\n";
    os << str;
    return os;
}