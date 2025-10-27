#include <SQLiteCpp/SQLiteCpp.h>
#include <iostream>
#include <set>
#include "Library.h"
#include "Book.h"
#include "Genre.h"

int main() {
	Book b1("9780140124996", "How to Solve It", { "George Polya" }, { Genre::SCIENCE }, true);
	Book b2("9780198724049", "Riddles of Existence", { "Earl Conee", "Theodore Sider" }, { Genre::PHILOSOPHY }, true);
	Book b3("9781844132393", "Man\'\'s Search for Meaning", { "Viktor Frankl" }, { Genre::PHILOSOPHY, Genre::PSYCHOLOGY }, true);
	Book b4("9781472147172", "The Happiness Trap", { "Russ Harris" }, { Genre::PSYCHOLOGY }, true);
	Book b5("9781572247055", "ACT Made Simple", { "Russ Harris" }, { Genre::PSYCHOLOGY }, true);
	Book b6("9780140446173", "Human, All Too Human", { "Friedrich Nietzsche" }, { Genre::PHILOSOPHY }, true);
	
	std::set<Book> bookSet = { b1, b2, b3, b4, b5, b6 };
	Library lib(bookSet);
	lib.clear();

	return 0;
}