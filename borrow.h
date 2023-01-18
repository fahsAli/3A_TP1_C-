#pragma once
#ifndef BORROW_HEADER
#define BORROW_HEADER
#include <string>
#include "date.h"
#include "reader.h"



namespace borrow{

    class Borrow{
        public:
            Borrow(reader::Reader& reader,std::string isbn="000000",date::Date borrow_date = date::Date());

            date::Date borrowDate() const;
            std::string ISBN() const;
            reader::Reader reader() const;
            bool validBorrow() const;

            void borrowDate(date::Date date);
            void ISBN(std::string isbn);
            void reader(reader::Reader reader);
            void validBorrow(bool valid);

            bool isNull();


        private:
            date::Date _borrow_date;
            std::string _ISBN;
            reader::Reader& _reader;
            bool _valid_borrow;

    };

    void addISBN(reader::Reader& reader,std::string isbn);
    void removeISBN(reader::Reader& reader,std::string isbn);
    std::ostream& operator<<(std::ostream& os,const Borrow& b);

}
#endif