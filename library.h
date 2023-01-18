#pragma once
#ifndef LIBRARY_HEADER
#define LIBRARY_HEADER

#include <vector>
#include <iostream>
#include <algorithm>

#include "date.h"
#include "author.h"
#include "book.h"
#include "borrow.h"
#include "reader.h"

namespace library {

    class Library{
        public:
            void init();
            void launch();
            void addReader();
            void addBook();
            void addAuthor();
            void showReaderProfile();
            void showAuthorProfile();
            void showBookDetails();
            void borrowBook();
            void returnBook();
            void borrowedBooks();
            void ranking();

        private:
            std::vector <author::Author> _authors_list;
            std::vector <book::Book> _books_list;
            std::vector <reader::Reader> _readers_list;
            std::vector <borrow::Borrow> _borrows_list;

    };

}
    std::ostream& operator << (std::ostream&os,std::vector <author::Author>  v);
    std::ostream& operator << (std::ostream&os,std::vector <book::Book>  v);
    std::ostream& operator << (std::ostream&os,std::vector <reader::Reader>  v);

#endif