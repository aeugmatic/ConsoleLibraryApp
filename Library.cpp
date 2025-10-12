#include "Library.h"
#include "Book.h"
#include "Genre.h"
#include <set>
#include <SQLiteCpp/SQLiteCpp.h>

// 
// CONSTRUCTORS
// 

Library::Library(std::set<Book> books) {

}

Library::Library(const Library &other) {

}

Library::Library() {

}

Library::~Library() {

}

// 
// OTHER METHODS
// 

// Create
void Library::addBook(Book newBook) {

}

void Library::addBooks(std::set<Book> newBooks) {

}

// Read
Book Library::getBook(std::string isbn) {

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