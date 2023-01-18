#pragma once
#ifndef BOOK_HEADER
#define BOOK_HEADER
#include <string>
#include <vector>
#include "author.h"
#include "date.h"
#include "borrow.h"

namespace book {
    class Book{

        public:
            Book(std::string title = "null",author::Author author=author::Author(),std::string lang="null",std::string type="null",date::Date pdate=date::Date(),std::string isbn="000000");

            std::string title() const;
            author::Author author() const;
            std::string language() const;
            std::string type() const;
            date::Date pubDate() const;
            std::string ISBN() const;
            bool status() const;
            std::vector <std::string> borrowList() const;

            void title(std::string title);
            void author(author::Author author);
            void language(std::string lang);
            void type(std::string type);
            void pubDate(date::Date date);
            void pubDate(int day,int month,int year);
            void ISBN(std::string isbn);
            void status(bool stat);
            void makeBorrow(std::string id);
            


        private:
            std::string _title;
            author::Author _author;
            std::string _language;
            std::string _type;
            date::Date _pub_date;
            std::string _ISBN;
            bool _status;
            std::vector <std::string> _borrow_list;
    };

        std::ostream& operator<<(std::ostream& os,const Book& b);

}

#endif