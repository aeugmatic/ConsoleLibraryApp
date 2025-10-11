#pragma once

#include "Genre.h"
#include <string>
#include <set>
#include <time.h>

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
	Book(const Book& other);
    Book();
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


    // Operator overloads
    bool operator==(const Book& other) const;
    bool operator!=(const Book& other) const; // Works on availability
    bool operator&&(const Book& other) const; // Works on availability
    bool operator||(const Book& other) const; // Works on availability
};