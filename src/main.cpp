#include "../include/Library.h"

using namespace std;

int main()
{
    Library library;
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "   LIBRARY MANAGEMENT SYSTEM\n";
        cout << "=====================================\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Exit\n";
        cout << "=====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                library.addBook();
                break;

            case 2:
                library.displayBooks();
                break;

            case 3:
                library.searchBook();
                break;

            case 4:
                library.deleteBook();
                break;

            case 5:
                library.issueBook();
                break;

            case 6:
                library.returnBook();
                break;

            case 7:
                cout << "\nThank you for using Library Management System!\n";
                break;

            default:
                cout << "\nInvalid Choice! Please try again.\n";
        }

    } while(choice != 7);

    return 0;
}