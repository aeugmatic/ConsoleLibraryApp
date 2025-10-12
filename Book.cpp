#include "Book.h"
#include "Genre.h"

#include <string>
#include <set>
#include <ostream>

// 
// CONSTRUCTORS
// 

Book::Book(std::string isbn, std::string title, std::set<std::string> authors, std::set<Genre> genres, bool available) {
	this->setIsbn(isbn);
	this->setTitle(title);
	this->setAuthors(authors);
	this->setGenres(genres);
	this->setAvailable(available);
}

Book::Book(const Book &other) {}
Book::~Book() {}

// 
// GETTERS
// 

std::string Book::getIsbn() const { return this->isbn; }
std::string Book::getTitle() const { return this->title; }
std::set<std::string> Book::getAuthors() const { return this->authors; }
std::set<Genre> Book::getGenres() const { return this->genres; }
bool Book::isAvailable() const { return this->available; }

// 
// SETTERS
// 

// NOTE: consider where and whether to use const and references in setter params

void Book::setIsbn(std::string isbn) {
	// --> PERFORM ISBN VALIDITY CHECK HERE <--
	this->isbn = isbn;
}

void Book::setTitle(std::string title) {
	this->title = title;
}

void Book::setAuthors(std::set<std::string> authors) {
	this->authors = authors;
}

void Book::setGenres(std::set<Genre> genres) {
	this->genres = genres;
}

void Book::setAvailable(bool available) {
	this->available = available;
}

// 
// OTHER METHODS
// 

std::string Book::authorsToString() const {
	std::string authorsStr = "";
	std::set<std::string>::iterator ita;
	for (ita = this->authors.begin(); ita != this->authors.end(); ita++) {
		authorsStr += (*ita) + ",";
	}
	authorsStr.resize(authorsStr.size() - 2);

	return authorsStr;
}

std::string Book::genresToString() const {
	std::string genresStr = "";
	std::set<std::string>::iterator ita;
	for (ita = this->authors.begin(); ita != this->authors.end(); ita++) {
		genresStr += (*ita) + ",";
	}
	genresStr.resize(genresStr.size() - 2);

	return genresStr;
}

std::string Book::toString() const {
	return "ISBN: " + this->isbn + "\n" +
		   "Title: " + this->title + "\n" +
		   "Authors: " + this->authorsToString() + "\n" +
		   "Genres: " + this->genresToString() + "\n" +
		   "Available?: " + ((this->available)? "yes" : "no") + "\n";
}

std::string Book::createInsertQuery() const {
	std::string result = "INSERT INTO books (isbn, title, authors, genres)";

	result += "\"" + this->getIsbn() + "\", \"";
	result += this->getTitle() + "\", \"";
	result += this->authorsToString() + "\", \"";
	result += this->genresToString() + "\", \"";
	result += ((this->available)? "1" : "0");
	result += ");";

	return result;
}

// 
// OPERATOR OVERLOADS
// 

bool Book::operator&&(const Book& other) const {
	return this->available && other.isAvailable();
}

bool Book::operator||(const Book& other) const {
	return this->available || other.isAvailable();
}

bool Book::operator!() const {
	return !this->available;
}

std::ostream &operator<<(std::ostream &os, const Book &b) {
	return (os << b.toString());
}