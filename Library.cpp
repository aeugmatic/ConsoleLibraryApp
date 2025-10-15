#include "Library.h"
#include "Book.h"
#include "Genre.h"
#include <set>
#include <sqlite3.h>
#include <SQLiteCpp/SQLiteCpp.h>

// 
// CONSTRUCTORS
// 

Library::Library(std::set<Book> books) : bookDb("books.db", SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE) {
	this->setupDb();
	this->addBooks(books); // Populate table (idk if the database inherently takes care of duplicates)
}

Library::Library() : bookDb("books.db", SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE) {
	this->setupDb();
}

Library::Library(const Library &other) : bookDb("books.db", SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE) {

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
		"available INTEGER)"
	);
}

// Create
void Library::addBook(Book newBook) {
	this->bookDb.exec(newBook.createInsertQuery());
	//this->bookDb.exec("INSERT INTO books (isbn, title, authors, genres, available ) VALUES (\"TEST\", \"TEST\", \"TEST\", \"TEST\", 1)");
}

void Library::addBooks(std::set<Book> newBooks) {
	std::set<Book>::iterator iter;
	for (iter = newBooks.begin(); iter != newBooks.end(); iter++) {
		Book cur = *iter;
		this->addBook(cur);
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
	SQLite::Statement query(this->bookDb, "SELECT * FROM books WHERE title=\"" + title + "\"");

	std::set<Book> s;
	return s;
}

std::set<Book> Library::searchAuthors(std::set<std::string> authors) {
	std::set<Book> s;
	return s;
}

std::set<Book> Library::searchGenres(std::set<Genre> genres) {
	std::set<Book> s;
	return s;
}

// Update
Book Library::updateBook(std::string isbn, Book newBook) {
	std::string a, b;
	return Book(a, b, {}, {}, true);
}

// Delete
Book Library::removeBook(std::string isbn) {
	std::string a, b;
	return Book(a, b, {}, {}, true);
}

void Library::clear() {
	this->bookDb.exec("DELETE FROM books;");
}