#pragma once

#include "Book.h"
#include "Genre.h"
#include <set>
#include <SQLiteCpp/SQLiteCpp.h>

class Library {
private:
	// Attributes
	SQLite::Database bookDb;

	// Methods
	void setupDb();
public:
	// Constructors
	Library(std::set<Book> books);
	Library();
	~Library();
	
	// Other methods
	void addBook(Book newBook);
	void addBooks(std::set<Book> newBooks);

	Book *getBook(std::string isbn);
	std::set<Book> searchTitle(std::string title);
	std::set<Book> searchAuthors(std::set<std::string> authors);
	std::set<Book> searchGenres(std::set<Genre> genres);

	Book updateBook(std::string isbn, Book newBook);

	Book removeBook(std::string isbn);
};