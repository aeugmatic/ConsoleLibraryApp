#include "Book.h"

#include <string>
#include <set>

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