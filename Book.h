#pragma once

#include "Genre.h"
#include <string>
#include <set>
#include <ostream>

class Book {
private:
	std::string isbn;
	std::string title;
	std::set<std::string> authors;
	std::set<Genre> genres;
	bool available;
public:
	// Constructors
	Book(std::string isbn, std::string title, std::set<std::string> authors, std::set<Genre> genres, bool available);
	Book(const Book &other);
	~Book();

	// Getters
	std::string getIsbn() const;
	std::string getTitle() const;
	std::set<std::string> getAuthors() const;
	std::set<Genre> getGenres() const;
	bool isAvailable() const;

	// Setters
	void setIsbn(std::string isbn);
	void setTitle(std::string title);
	void setAuthors(std::set<std::string> authors);
	void setGenres(std::set<Genre> genres);
	void setAvailable(bool available);

	// Other methods
	std::string toString() const;

	// Operator overloads
	bool operator&&(const Book &other) const;   // Works on availability
	bool operator||(const Book &other) const;   // Works on availability
	bool operator!() const;                     // Works on availability
};

std::ostream &operator<<(std::ostream &os, const Book &b);