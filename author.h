#pragma once
#ifndef AUTHOR_HEADER
#define AUTHOR_HEADER
#include <string>
#include "date.h"
#include <iostream>

namespace author{
    
    class Author{   
        public:
            Author(std::string fname="null",std::string lname="null",date::Date date=date::Date());          
            bool isNull() const;

            std::string firstName() const;
            std::string lastName() const;
            std::string id() const;
            date::Date bdate() const;

            void firstName(std::string fname);
            void lastName(std::string lname);
            void bdate(int day,int month,int year);
            void bdate(date::Date d);

        private:
            std::string _id;
            std::string _fname;
            std::string _lname;
            date::Date _bdate;


    };

    std::ostream& operator<<(std::ostream& os,const Author aut);
    bool operator==(const Author aut1, const Author aut2);

}



#endif