#include <iostream>
#include <cstring>
using namespace std;

class Book
{
    double price;
    int pages;
    char *title;
    char *author;

public:
    Book(double pr, int pa, const char *t, const char *a);
    Book(const Book &book);
    ~Book();
};

    Book :: Book(double pr, int pa, const char *t, const char *a){
        this -> price = pr;
        this -> pages = pa;
        int len = strlen(t);
        this -> title = new char [len +1];
        strcpy(this-> title , t);
        int leng = strlen(a);
        this -> author = new char [leng +1];
        strcpy(this-> author , a);

    }

    Book:: Book(const Book &book){
        this -> price = book.price;
        this -> pages = book.pages;
        int len = strlen(book.title);
        this -> title = new char [len +1];
        strcpy (this -> title, book.title);

        int leng = strlen(book.author);
        this -> author = new char [leng +1];
        strcpy (this -> author, book.author);

    }

    Book :: ~Book(){
        if(author)
            delete[] author;
        if(title)
            delete[] title; 

    }
int main() {
    Book example(20000, 876, "examplebookname", "chan Park");
    Book example2(example);


    return 0;
}