#include "../include/Library.h"

// Constructor
Library::Library()
{
    loadFromFile();
}

// Add New Book
void Library::addBook()
{
    int id, year;
    std::string title, author;

    std::cout << "\nEnter Book ID: ";
    std::cin >> id;

    // Check Duplicate ID
    for(size_t i = 0; i < books.size(); i++)
    {
        if(books[i].getBookID() == id)
        {
            std::cout << "\nBook ID already exists!\n";
            return;
        }
    }

    std::cin.ignore();

    std::cout << "Enter Book Title: ";
    std::getline(std::cin, title);

    std::cout << "Enter Author Name: ";
    std::getline(std::cin, author);

    std::cout << "Enter Publication Year: ";
    std::cin >> year;

    Book newBook(id, title, author, year, false);

    books.push_back(newBook);

    saveToFile();

    std::cout << "\nBook Added Successfully!\n";
}

// Display All Books
void Library::displayBooks()
{
    if(books.empty())
    {
        std::cout << "\nNo books available in the library.\n";
        return;
    }

    std::cout << "\n========== LIBRARY BOOKS ==========" << std::endl;

    for(size_t i = 0; i < books.size(); i++)
    {
        books[i].display();
    }

    std::cout << "\nTotal Books : " << books.size() << std::endl;
}
// Search Book by ID
void Library::searchBook()
{
    int id;

    cout << "\nEnter Book ID to Search: ";
    cin >> id;

    for(int i = 0; i < books.size(); i++)
    {
        if(books[i].getBookID() == id)
        {
            cout << "\nBook Found!\n";
            books[i].display();
            return;
        }
    }

    cout << "\nBook Not Found!\n";
}
// Delete Book
void Library::deleteBook()
{
    int id;

    cout << "\nEnter Book ID to Delete: ";
    cin >> id;

    for(int i = 0; i < books.size(); i++)
    {
        if(books[i].getBookID() == id)
        {
            books.erase(books.begin() + i);

            saveToFile();

            cout << "\nBook Deleted Successfully!\n";
            return;
        }
    }

    cout << "\nBook Not Found!\n";
}
// Issue Book
void Library::issueBook()
{
    int id;

    cout << "\nEnter Book ID to Issue: ";
    cin >> id;

    for(int i = 0; i < books.size(); i++)
    {
        if(books[i].getBookID() == id)
        {
            if(books[i].isIssued())
            {
                cout << "\nBook is already issued!\n";
            }
            else
            {
                books[i].setIssued(true);

                saveToFile();

                cout << "\nBook Issued Successfully!\n";
            }

            return;
        }
    }

    cout << "\nBook Not Found!\n";
}
// Return Book
void Library::returnBook()
{
    int id;

    cout << "\nEnter Book ID to Return: ";
    cin >> id;

    for(int i = 0; i < books.size(); i++)
    {
        if(books[i].getBookID() == id)
        {
            if(!books[i].isIssued())
            {
                cout << "\nBook is already available!\n";
            }
            else
            {
                books[i].setIssued(false);

                saveToFile();

                cout << "\nBook Returned Successfully!\n";
            }

            return;
        }
    }

    cout << "\nBook Not Found!\n";
}
// Save Books to File
void Library::saveToFile()
{
    ofstream file("data/books.txt");

    if(!file)
    {
        cout << "\nError opening file!\n";
        return;
    }

    for(int i = 0; i < books.size(); i++)
    {
        file << books[i].toFileString() << endl;
    }

    file.close();
}
// Load Books from File
void Library::loadFromFile()
{
    ifstream file("data/books.txt");

    if(!file)
    {
        return;
    }

    books.clear();

    string line;

    while(getline(file, line))
    {
        stringstream ss(line);

        string id, title, author, year, status;

        getline(ss, id, '|');
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, year, '|');
        getline(ss, status, '|');

        Book b(
            stoi(id),
            title,
            author,
            stoi(year),
            stoi(status)
        );

        books.push_back(b);
    }

    file.close();
}
