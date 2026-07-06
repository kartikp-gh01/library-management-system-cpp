#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
    int bookID;
    string title;
    string author;
    int year;
    bool issued;

public:
    // Constructors
    Book();
    Book(int id, string t, string a, int y, bool status = false);

    // Getters
    int getBookID() const;
    string getTitle() const;
    string getAuthor() const;
    int getYear() const;
    bool isIssued() const;

    // Setter
    void setIssued(bool status);

    // Display
    void display() const;

    // File Handling
    string toFileString() const;
};

#endif