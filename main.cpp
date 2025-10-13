#include <iostream>
#include "Library.h"
#include "Book.h"
#include <sqlite3.h>
#include <SQLiteCpp/SQLiteCpp.h>
#include <set>
#include "Genre.h"

int main() {
	Book b("978-0-14-012499-6", "How to Solve It", { "George Polya" }, { Genre::SCIENCE }, true);
	std::set<Book> bookSet = { b };
	Library lib(bookSet);

	Book *res = lib.getBook("978-0-14-012499-6");

	return 0;
}