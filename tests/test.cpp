#include "../include/Book.h"
#include <cassert>

int main()
{
    Book b(101, "C++", "Bjarne", 2013);

    assert(b.getBookID() == 101);
    assert(b.getTitle() == "C++");
    assert(b.getAuthor() == "Bjarne");
    assert(b.getYear() == 2013);
    assert(b.isIssued() == false);

    return 0;
}