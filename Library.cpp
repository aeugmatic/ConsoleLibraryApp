#include "Library.h"
#include "Book.h"
#include "Genre.h"
#include <set>
#include <sqlite3.h>
#include <SQLiteCpp/SQLiteCpp.h>
#include <sstream>

// TEMP
#include <iostream>


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

Book Library::rowToBook(SQLite::Statement &query) const {
	std::string resIsbn = query.getColumn(0).getString();
	std::string resTitle = query.getColumn(1).getString();
	std::set<std::string> resAuthors = authorsFromStr(query.getColumn(2).getString());
	std::set<Genre> resGenre = genresFromStr(query.getColumn(3).getString());
	bool resAvailable = query.getColumn(4).getInt();

	return Book(
		resIsbn,
		resTitle,
		resAuthors,
		resGenre,
		resAvailable
	);
}

// PRIVATE: create insert query for a book
std::string Library::createInsertQuery(Book &book) const {
	// Add "OR IGNORE" to avoid issues due to primary key uniqueness violation
	std::string result =
		"INSERT OR IGNORE INTO books (isbn, title, authors, genres, available) VALUES ("
		"'" + book.getIsbn() + "', "
		"'" + book.getTitle() + "', "
		"'" + book.authorsToString() + "', "
		"'" + book.genresToString() + "', "
		+ ((book.isAvailable())? "1" : "0") + ");";

	//std::cout << result << std::endl;

	return result;
}

// PRIVATE: convert author string into a set of author strings
std::set<std::string> Library::authorsFromStr(std::string authorsStr) const {
	// Split string using streams
	std::set<std::string> authorsSet;
	std::string author;
	std::istringstream ss(authorsStr);

	while (std::getline(ss, author, ',')) {
		authorsSet.insert(author);
	}

	return authorsSet;
}

// PRIVATE: convert genres string into a set of Genre enums
std::set<Genre> Library::genresFromStr(std::string genresStr) const {
	// Split string using streams
	std::set<Genre> genresSet;
	std::string genre;
	std::istringstream ss(genresStr);

	while (std::getline(ss, genre, ',')) {
		Genre g = stringToGenre(genre);
		genresSet.insert(g);
	}

	return genresSet;
}

// Create
void Library::addBook(Book newBook) {
	this->bookDb.exec(createInsertQuery(newBook));
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
Book Library::getBook(std::string isbn) const {
	SQLite::Statement query(this->bookDb, "SELECT * FROM books WHERE isbn='" + isbn + "';");

	query.executeStep();
	return rowToBook(query);
}

std::set<Book> Library::searchTitle(std::string text) const {
	SQLite::Statement query(this->bookDb, "SELECT * FROM books WHERE title LIKE '%" + text + "%';");

	std::set<Book> result;
	while (query.executeStep()) {
		Book b = rowToBook(query);
		result.insert(b);
	}

	return result;
}

std::set<Book> Library::searchAuthors(std::set<std::string> authors) const {
	std::string queryStr = "SELECT * FROM books WHERE authors LIKE ";
	
	// Build query string
	std::set<std::string>::iterator iter;
	for (iter = authors.begin(); iter != authors.end(); iter++) {
		queryStr += "'%" + (*iter) + "%' OR authors LIKE ";
	}
	queryStr = queryStr.substr(0, queryStr.size() - 17) + ";"; // Refactor magic number (17 = no. of chars to remove from final item)

	//std::cout << queryStr << std::endl;

	SQLite::Statement query(this->bookDb, queryStr);
	std::set<Book> result;
	while (query.executeStep()) {
		Book b = rowToBook(query);
		result.insert(b);
	}

	return result;
}

std::set<Book> Library::searchGenres(std::set<Genre> genres) const {
	std::string queryStr = "SELECT * FROM books WHERE genres LIKE ";

	// Build query string
	std::set<Genre>::iterator iter;
	for (iter = genres.begin(); iter != genres.end(); iter++) {
		queryStr += "'%" + genreToString(*iter) + "%' OR genres LIKE ";
	}
	queryStr = queryStr.substr(0, queryStr.size() - 16) + ";"; // Refactor magic number (16 = no. of chars to remove from final item)

	std::cout << queryStr << std::endl;

	SQLite::Statement query(this->bookDb, queryStr);
	std::set<Book> result;
	while (query.executeStep()) {
		Book b = rowToBook(query);
		result.insert(b);
	}

	return result;
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