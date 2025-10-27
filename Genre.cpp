#include "Genre.h"
#include <string>

// TODO:
// - Create method in Library (or elsewhere) that splits the author string into a set of strings
// - Create method in Library (or elsewhere) that splits the genre string into a set of genre enum values
// - Implement these split methods in the getBook method in Library so that it finally works

std::unordered_map<Genre, std::string> genreStrMap = {
    {Genre::ACTION, "Action"},
    {Genre::ADVENTURE, "Adventure"},
    {Genre::BIOGRAPHY, "Biography"},
    {Genre::CLASSICS, "Classics"},
    {Genre::CRIME, "Crime"},
    {Genre::DYSTOPIAN, "Dystopian"},
    {Genre::FANTASY, "Fantasy"},
    {Genre::HISTORY, "History"},
    {Genre::HORROR, "Horror"},
    {Genre::HUMOUR, "Humour"},
    {Genre::MYSTERY, "Mystery"},
    {Genre::NOIR, "Noir"},
    {Genre::OTHER, "Other"},
    {Genre::POLITICS, "Politics"},
    {Genre::PHILOSOPHY, "Philosophy"},
    {Genre::PSYCHOLOGY, "Psychology"},
    {Genre::RELIGION, "Religion"},
    {Genre::ROMANCE, "Romance"},
    {Genre::SCIENCE, "Science"},
    {Genre::SCIFI, "Science Fiction"},
    {Genre::SPORTS, "Sports"},
    {Genre::SUPERNATURAL, "Supernatural"},
    {Genre::TALES_MYTHOLOGY, "Tales & Mythology"},
    {Genre::THRILLER, "Thriller"},
    {Genre::WAR_MILITARY, "War & Military"}
};

std::string genreToString(Genre g) {
    return genreStrMap[g];
}

Genre stringToGenre(std::string gStr) {
    Genre result;
    
    std::unordered_map<Genre, std::string>::iterator iter;
    for (iter = genreStrMap.begin(); iter != genreStrMap.end(); iter++) {
        Genre g = iter->first;
        if (genreStrMap[g] == gStr) return g;
    }

    return Genre::OTHER;
}