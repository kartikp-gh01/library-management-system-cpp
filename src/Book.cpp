#include "../include/Book.h"

// Default Constructor
Book::Book()
{
    bookID = 0;
    title = "";
    author = "";
    year = 0;
    issued = false;
}

// Parameterized Constructor
Book::Book(int id, string t, string a, int y, bool status)
{
    bookID = id;
    title = t;
    author = a;
    year = y;
    issued = status;
}

// Getters
int Book::getBookID() const
{
    return bookID;
}

string Book::getTitle() const
{
    return title;
}

string Book::getAuthor() const
{
    return author;
}

int Book::getYear() const
{
    return year;
}

bool Book::isIssued() const
{
    return issued;
}

// Setter
void Book::setIssued(bool status)
{
    issued = status;
}

// Display Function
void Book::display() const
{
    cout << "\n-----------------------------\n";
    cout << "Book ID : " << bookID << endl;
    cout << "Title   : " << title << endl;
    cout << "Author  : " << author << endl;
    cout << "Year    : " << year << endl;
    cout << "Status  : ";

    if(issued)
        cout << "Issued";
    else
        cout << "Available";

    cout << endl;
}

// Convert object to file format
string Book::toFileString() const
{
    return to_string(bookID) + "|" +
           title + "|" +
           author + "|" +
           to_string(year) + "|" +
           to_string(issued);
}