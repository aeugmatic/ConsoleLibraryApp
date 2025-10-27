#include <iostream>
#include "Library.h"
#include "Book.h"
#include <sqlite3.h>
#include <SQLiteCpp/SQLiteCpp.h>
#include <set>
#include "Genre.h"

int main() {
	Book b1("978-0-14-012499-6", "How to Solve It", { "George Polya" }, { Genre::SCIENCE }, true);
	Book b2("978-0-19-872404-9", "Riddles of Existence", { "Earl Conee", "Theodore Sider" }, { Genre::PHILOSOPHY }, true);
	Book b3("978-1-84413-239-3", "Man\'\'s Search for Meaning", { "Viktor Frankl" }, { Genre::PHILOSOPHY, Genre::PSYCHOLOGY }, true);
	Book b4("978-1-4721-4717-2", "The Happiness Trap", { "Russ Harris" }, { Genre::PSYCHOLOGY }, true);
	
	std::set<Book> bookSet = { b1, b2, b3, b4 };

	Library lib(bookSet);
	
	Book *res = lib.getBook("978-1-84413-239-3");
	std::cout << (*res) << std::endl;

	delete res;

	lib.clear();

	return 0;
}