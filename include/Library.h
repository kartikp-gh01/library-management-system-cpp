#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "../include/Book.h"

using namespace std;

class Library
{
private:
    vector<Book> books;

public:
    // Constructor
    Library();

    // Book Operations
    void addBook();
    void displayBooks();
    void searchBook();
    void deleteBook();

    // Issue / Return
    void issueBook();
    void returnBook();

    // File Handling
    void saveToFile();
    void loadFromFile();
};

#endif