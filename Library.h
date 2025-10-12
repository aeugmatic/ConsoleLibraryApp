#pragma once

#include "Book.h"
#include "Genre.h"
#include <set>
#include <SQLiteCpp/SQLiteCpp.h>

class Library {
private:
	SQLite::Database bookDb;
public:
	// Constructors
	Library(SQLite::Database bookDb);
	Library();
	
	// Other methods
	void addBook(Book newBook);

	Book getBook(std::string isbn);
	std::set<Book> searchTitle(std::string title);
	std::set<Book> searchAuthors(std::set<std::string> authors);
	std::set<Book> searchGenres(std::set<Genre> genres);

	Book updateBook(std::string isbn, Book updated);

	Book removeBook(std::string isbn);
};