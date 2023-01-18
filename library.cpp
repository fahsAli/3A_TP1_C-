#include "library.h"

void library::Library::init(){
    author::Author auth1("William","Shakespeare",date::Date(26,4,1564));
    author::Author auth2("Agatha","Christie",date::Date(15,9,1890));
    author::Author auth3("virginia","woolf",date::Date(25,1,1882));

    _authors_list.push_back(auth1);
    _authors_list.push_back(auth2);
    _authors_list.push_back(auth3);

    reader::Reader read1("Ali","Fahs");
    reader::Reader read2("Tom","Lantelme");
    reader::Reader read3("Maxime","Therie");

    _readers_list.push_back(read1);
    _readers_list.push_back(read2);
    _readers_list.push_back(read3);

    book::Book book1("The Tempest",auth1,"english","drama",date::Date(1,1,1623),"000001");
    book::Book book2("The Life and Death of King John",auth1,"english","history",date::Date(1,1,1598),"000002");
    book::Book book3("Romeo and Juliette",auth1,"english","drama",date::Date(1,1,1597),"000003");
    book::Book book4("Richard II",auth1,"english","history",date::Date(1,1,1595),"000004");
    
    book::Book book5("The Mysterious Affair at Styles",auth2,"english","roman",date::Date(2,2,1920),"000005");
    book::Book book6("Mr Brown",auth2,"english","roman",date::Date(2,2,1922),"000006");
    book::Book book7("Murder on the Links",auth2,"english","roman",date::Date(2,2,1923),"000007");
    
    book::Book book8("The Voyage Out",auth3,"english","roman",date::Date(3,3,1915),"000008");
    book::Book book9("Night and Day",auth3,"english","roman",date::Date(3,3,1919),"000009");
    book::Book book10("Jacob's Room ",auth3,"english","roman",date::Date(3,3,1920),"000010");

    _books_list.push_back(book1);
    _books_list.push_back(book2);
    _books_list.push_back(book3);
    _books_list.push_back(book4);
    _books_list.push_back(book5);
    _books_list.push_back(book6);
    _books_list.push_back(book7);
    _books_list.push_back(book8);
    _books_list.push_back(book9);
    _books_list.push_back(book10);
}

void library::Library::addReader(){
    
    std::string fname="",lname="";
    std::cout << "enter first name : ";
    std::cin >> fname; 

    std::cout << "enter last name : ";
    std::cin >> lname; std::cout << std::endl;

    _readers_list.push_back(reader::Reader(fname,lname));
}

void library::Library::addAuthor(){

    std::string fname="",lname="";
    int day=0,month=0,year=0;
    std::cout << "enter first name : ";
    std::cin >> fname;

    std::cout << "enter last name : ";
    std::cin >> lname;

    std::cout << "> now please fill the birth date : " << std::endl;
   
    std::cout << "enter day :";
    std::cin >> day;
   
    std::cout << "enter month : ";
    std::cin >> month;
   
    std::cout << "enter year :";
    std::cin >> year; std::cout << std::endl;

    _authors_list.push_back(author::Author(fname,lname,date::Date(day,month,year)));

}


void library::Library::addBook(){

    std::string title="",lang="",type="",isbn="";
    int day=0,month=0,year=0,option=0;
    author::Author author = author::Author();

    std::cout << "enter title : ";
    std::cin >> title;
    
    std::cout << "enter language : ";
    std::cin >> lang;
    
    std::cout << "enter type :";
    std::cin >> type;

    std::cout << "enter ISBN number : ";
    std::cin >> isbn;

    std::cout << "> now please fill the publish date : " << std::endl;
   
    std::cout << "enter day :";
    std::cin >> day;
   
    std::cout << "enter month : ";
    std::cin >> month;
   
    std::cout << "enter year :";
    std::cin >> year; std::cout << std::endl;

    std::cout << "> now choose the author : " << std::endl;
    std::cout << _authors_list;
    std::cout << (_authors_list.size()+1) << ") author not here ? (add author) " <<std::endl;
    std::cin >> option;

    while((option < 1)||(option>(_authors_list.size()+1))){
        std::cout << "please choose again : "<< std::endl;
        std::cin >> option; std::cout << std::endl;
    }

    if(option==(_authors_list.size()+1)){
        this->addAuthor();
        _books_list.push_back(book::Book(title,*(_authors_list.end()-1),lang,type,date::Date(day,month,year),isbn));
    }else{
        _books_list.push_back(book::Book(title,_authors_list.at(option-1),lang,type,date::Date(day,month,year),isbn));
    }

    std::cout << "Done" << std::endl;

}

void library::Library::showReaderProfile(){

    int option=0; 
    std::cout << std::endl;
    std::cout << _readers_list;
    std::cout << "enter the profile number : ";
    std::cin >> option;
    std::cout << std::endl;
    std::cout << std::endl;
    while((option < 1)||(option>_readers_list.size())){
        std::cout << "please choose again : "<< std::endl;
        std::cin >> option;
    }

    std::cout << _readers_list.at(option-1);
    std::cout << _readers_list.at(option-1).ISBN_list();
    std::cout << std::endl;
}

void library::Library::showAuthorProfile(){

    int option=0; 
    std::cout << std::endl;
    std::cout << _authors_list;
    std::cout << "enter the profile number : ";
    std::cin >> option;
    std::cout << std::endl;
    std::cout << std::endl;
    while((option < 1)||(option>_authors_list.size())){
        std::cout << "please choose again : "<< std::endl;
        std::cin >> option;
    }

    std::cout << _authors_list.at(option-1);
    std::cout << "birth date : " << _authors_list.at(option-1).bdate();
    std::cout << "=> books list by " << _authors_list.at(option-1).id() << ": \n";
    for(auto it=_books_list.begin();it!=_books_list.end();++it){
        if(it->author() == _authors_list.at(option-1)){
            std::cout << ">>" << it->title() << std::endl;
        }
    }
    std::cout << std::endl;
}

void library::Library::showBookDetails(){
    int option=1;
    std::cout << "books list : " << std::endl;
    for(auto it=_books_list.begin();it!=_books_list.end();++it){
        std::cout << option << ") " << it->title() << std::endl;
        option++;
    }
    option = 0;
    
    std::cout << "enter the book number : ";
    std::cin >> option;
    std::cout << std::endl;
    while((option < 1)||(option>_books_list.size())){
        std::cout << "please choose again : "<< std::endl;
        std::cin >> option;
    }

    std::cout << _books_list.at(option-1);
    std::cout << _books_list.at(option-1).borrowList();
    std::cout << "------------------------\n";
    std::cout << std::endl;
}


void library::Library::borrowBook(){
    int option1=0,option2=1,day=0,month=0,year=0; 
    std::cout << "select your profile : " << std::endl;
    std::cout << _readers_list;
    std::cout << "enter the profile number : ";
    std::cin >> option1; 
    std::cout << std::endl;
    std::cout << std::endl;
    while((option1 < 1)||(option1>_readers_list.size())){
        std::cout << "please choose again : "<< std::endl;
        std::cin >> option1;
    }

    std::cout << "books list : " << std::endl;
    for(auto it=_books_list.begin();it!=_books_list.end();++it){
        std::cout << option2 << ") " << it->title() << std::endl;
        option2++;
    }
    option2 = 0;
    
    std::cout << "enter the book number : ";
    std::cin >> option2;
    std::cout << std::endl;

    while(((option2 < 1)||(option2>_books_list.size()+1))||(!_books_list.at(option2-1).status())){
        if(!_books_list.at(option2-1).status()){
            std::cout << "book already borrowed please choose another or cancel ( option :  "<< _books_list.size()+1 << ") : "<< std::endl;
            std::cin >> option2;
            if(option2 >= 11){
                break;
            }
        }else {
            std::cout << "please choose again : "<< std::endl;
            std::cin >> option2;
        }
    }

    if(option2 < (_books_list.size()+1)){
        std::cout << "> now please fill the borrow date : " << std::endl;
    
        std::cout << "enter day :";
        std::cin >> day;
    
        std::cout << "enter month : ";
        std::cin >> month;
    
        std::cout << "enter year :";
        std::cin >> year; std::cout << std::endl;

        _borrows_list.push_back(borrow::Borrow(_readers_list.at(option1-1),_books_list.at(option2-1).ISBN(),date::Date(day,month,year)));
        _books_list.at(option2-1).makeBorrow(_readers_list.at(option1-1).id());
        _books_list.at(option2-1).status(false);
    }
}

void library::Library::returnBook(){
    int option1=0,option2=1,cpt=0; 
    std::cout << "select your profile : " << std::endl;
    std::cout << _readers_list;
    std::cout << "enter the profile number : ";
    std::cin >> option1; 
    std::cout << std::endl;
    std::cout << std::endl;
    while((option1 < 1)||(option1>_readers_list.size())){
        std::cout << "please choose again : "<< std::endl;
        std::cin >> option1;
    }

    std::cout << "books list : " << std::endl;
    std::cout << _readers_list.at(option1-1).ISBN_list();
    option2 = 0;
    
    std::cout << "enter the book number : ";
    std::cin >> option2;
    std::cout << std::endl;

    while((option2<1)||(option2>_readers_list.at(option1-1).ISBN_list().size())){
 
        std::cout << "please choose again : "<< std::endl;
        std::cin >> option2;
    }

    std::string isbn = _readers_list.at(option1-1).ISBN_list().at(option2-1);
    _readers_list.at(option1-1).removeisbn(_readers_list.at(option1-1).ISBN_list().at(option2-1));
   
    for(auto it=_books_list.begin();it!=_books_list.end();++it){
        if(_books_list.at(cpt).ISBN() == isbn){
             //_books_list.at(cpt).status(true);
             it->status(true);
        }
        cpt++;
    }
}

void library::Library::borrowedBooks(){
    int cpt=1;
    std::cout << "borrowed books list : \n";
    for(auto it=_books_list.begin();it!=_books_list.end();++it){
        if(it->status() == false){
            std::cout << ">>" << it->title() << std::endl;
            cpt++;
        }
    }
    std::cout << "- percentage of borrowed books = " << (100.0*(cpt-1))/_books_list.size() << std::endl;
    std::cout << std::endl;
}

void library::Library::ranking(){
    std::cout << "ranking : " << std::endl;
    std::vector <reader::Reader> vec = _readers_list;
    std::sort(vec.begin(),vec.end(),[](const reader::Reader read1,const reader::Reader read2){return read1.borrowedBooksNumber()>read2.borrowedBooksNumber();});
    std::cout << vec << std::endl;
}


void library::Library::launch(){
    
    this->init();

    int option = 0;
    bool end = false;

    std::cout << "=============================================" << std::endl;
    std::cout << "           welcome to ESIREM library         " << std::endl;
    std::cout << "=============================================" << std::endl;

    while(!end){
        std::cout << "how can i help you ?" << std::endl;
        std::cout << "1)  add a reader" << std::endl; 
        std::cout << "2)  add a book" << std::endl;   
        std::cout << "3)  add an author" << std::endl;
        std::cout << "4)  borrow a book" << std::endl; 
        std::cout << "5)  return a book" << std::endl;
        std::cout << "6)  show Reader profile" << std::endl;
        std::cout << "7)  show Author profile" << std::endl;
        std::cout << "8)  show Book details" << std::endl;
        std::cout << "9)  borrowed books" << std::endl;
        std::cout << "10) ranking" << std::endl; 
        std::cout << "11) quit" << std::endl;        
        
        std::cout << "enter your choice : ";
        std::cin >> option; std::cout << std::endl;

        while((option < 1)||(option>15)){
            std::cout << "please choose again : "<< std::endl;
            std::cin >> option;
        }

        switch (option)
        {
            case 1:
                this->addReader();
                break;
            case 2:
                this->addBook();
                break;
            case 3:
                this->addAuthor();
                break;
            case 4:
                this->borrowBook();
                break;
            case 5:
                this->returnBook();
                break;
            case 6:
                this->showReaderProfile();
                break;
            case 7:
                this->showAuthorProfile();
                break;
            case 8:
                this->showBookDetails();
                break;
            case 9:
                this->borrowedBooks();
                break;
            case 10:
                this->ranking();
                break;
            case 11:
                end=true;
                break;
        }

    }


}

std::ostream& operator << (std::ostream&os,std::vector <author::Author>  v){
    int i=1;
    os << ">> authors list : \n";
    for (auto it = v.begin();(it != v.end())&&(v.size()>0); ++it)
    {
        os << i << ") " << *it;
        i++;
    }
    os << "\n";
    return os;
}


std::ostream& operator << (std::ostream&os,std::vector <book::Book>  v){
    int i=1;
    os << ">> books list : \n";
    for (auto it = v.begin();(it != v.end())&&(v.size()>0); ++it)
    {
        os << i << ") " << *it << "\n" ;
        i++;
    }
    return os;
}

std::ostream& operator << (std::ostream&os,std::vector <reader::Reader>  v){
    int i=1;
    os << ">> readers list : \n";
    for (auto it = v.begin();(it != v.end())&&(v.size()>0); ++it)
    {
        os << i << ") " << *it;
        i++;
    }
    return os;
}



