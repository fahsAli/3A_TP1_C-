#pragma once
#ifndef READER_HEADER
#define READER_HAEDER
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>

namespace reader{

    class Reader{
        public:
            Reader(std::string fname="null",std::string lname="null");

            bool isNull() const;

            std::string id() const;
            std::string firstName() const;
            std::string lastName() const;
            std::vector <std::string> ISBN_list() const;
            std::string getFullName() const;
            int borrowedBooksNumber() const;

            void addisbn(std::string isbn);
            void removeisbn(std::string isbn);
            void id(std::string id);
            void firstName(std::string fname);
            void lastName(std::string lname);
            
        private:
            std::string _id;
            std::string _fname;
            std::string _lname;
            std::vector <std::string> _ISBN_list;
            int _borrowed_books_number;


    };
     
    std::ostream& operator<<(std::ostream& os,const Reader& read);
}       
    std::ostream& operator << (std::ostream&os,std::vector <std::string>  v);

#endif