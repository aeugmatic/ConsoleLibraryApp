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

Book::Book(const Book& other) {

}

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

void Book::setIsbn(std::string &isbn) {
	// --> PERFORM ISBN VALIDITY CHECK HERE <--
	this->isbn = isbn;
}

void Book::setTitle(std::string &title) {
	this->title = title;
}

void Book::setAuthors(std::set<std::string> &authors) {
	this->authors = authors;
}

void Book::setGenres(std::set<Genre> &genres) {
	this->genres = genres;
}

void Book::setAvailable(bool available) {
	this->available = available;
}

// 
// OTHER METHODS
// 

std::string Book::toString() const {
	std::string authorsStr = "Authors: ";
	std::string genresStr = "Genres: ";
	std::string availableStr = (this->available)? "yes" : "no";

	// Authors string
	std::set<std::string>::iterator ita;
	for (ita = this->authors.begin(); ita != this->authors.end(); ita++) {
		authorsStr += (*ita) + ", ";
	}
	authorsStr.resize(authorsStr.size() - 2);

	// Genres string
	std::set<Genre>::iterator itg;
	for (itg = this->genres.begin(); itg != this->genres.end(); itg++) {
		authorsStr += genreToString(*itg) + ", ";
	}
	authorsStr.resize(authorsStr.size() - 2);

	return "ISBN: " + this->isbn + "\n" +
		   "Title: " + this->title + "\n" +
		   authorsStr + "\n" +
		   genresStr + "\n" +
		   availableStr + "\n";
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

std::ostream &::operator<<(std::ostream &os, const Book &b) {
	return (os << b.toString());
}