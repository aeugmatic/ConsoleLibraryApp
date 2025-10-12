#include "Library.h"
#include "Book.h"
#include "Genre.h"
#include <set>
#include <SQLiteCpp/SQLiteCpp.h>

// 
// CONSTRUCTORS
// 

Library::Library(std::set<Book> books) : bookDb("books.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE) {
	this->setupDb();
	this->addBooks(books); // Populate table (idk if the database inherently takes care of duplicates)
}

Library::Library() : bookDb("books.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE) {
	this->setupDb();
}

Library::~Library() {}

// 
// OTHER METHODS
// 

// PRIVATE: create DB
void Library::setupDb() {
	// Creates main books table if it doesn't exist yet
	this->bookDb.exec(
		"CREATE TABLE IF NOT EXISTS books("
		"isbn TEXT PRIMARY KEY, "
		"title TEXT, "
		"authors TEXT, "	// UNNORMALISED VER: desc. order comma-separated within text
		"genres TEXT, "		// UNNORMALISED VER: desc. order comma-separated within text
		"available BOOL)"
	);
}

// Create
void Library::addBook(Book newBook) {
	this->bookDb.exec(newBook.createInsertQuery());
}

void Library::addBooks(std::set<Book> newBooks) {
	std::set<Book>::iterator iter;
	for (iter = newBooks.begin(); iter != newBooks.end(); iter++) {
		Book cur = *iter;
		this->bookDb.exec(cur.createInsertQuery());
	}
}

// Read
Book *Library::getBook(std::string isbn) {
	SQLite::Statement query(this->bookDb, "SELECT * FROM books WHERE isbn=\"" + isbn + "\"");
	
	std::string resIsbn = query.getColumn(0).getString();
	std::string resTitle = query.getColumn(1).getString();
	std::set<std::string> resAuthors;
	std::set<Genre> resGenre;
	bool resAvailable = false;

	return new Book(
		resIsbn,
		resTitle,
		resAuthors,
		resGenre,
		resAvailable
	);
}

std::set<Book> Library::searchTitle(std::string title) {

}

std::set<Book> Library::searchAuthors(std::set<std::string> authors) {

}

std::set<Book> Library::searchGenres(std::set<Genre> genres) {

}

// Update
Book Library::updateBook(std::string isbn, Book newBook) {

}

// Delete
Book Library::removeBook(std::string isbn) {

}