#include "Genre.h"
#include <string>

std::string genreToString(Genre g) {
	switch (g) {
	case Genre::ACTION:
		return "Action";
	case Genre::ADVENTURE:
		return "Adventure";
	case Genre::BIOGRAPHY:
		return "Biography";
	case Genre::CLASSICS:
		return "Classics";
	case Genre::CRIME:
		return "Crime";
	case Genre::DYSTOPIAN:
		return "Dystopian";
	case Genre::EROTICA:
		return "Erotica";
	case Genre::FANTASY:
		return "Fantasy";
	case Genre::HISTORY:
		return "History";
	case Genre::HORROR:
		return "Horror";
	case Genre::HUMOUR:
		return "Humour";
	case Genre::MYSTERY:
		return "Mystery";
	case Genre::NOIR:
		return "Noir";
	case Genre::PHILOSOPHY:
		return "Philosophy";
	case Genre::POLITICS:
		return "Politics";
	case Genre::PSYCHOLOGY:
		return "Psychology";
	case Genre::RELIGION:
		return "Religion";
	case Genre::ROMANCE:
		return "Romance";
	case Genre::SCIENCE:
		return "Science";
	case Genre::SCIFI:
		return "Science Fiction";
	case Genre::SPORTS:
		return "Sports";
	case Genre::SUPERNATURAL:
		return "Supernatural";
	case Genre::TALES_MYTHOLOGY:
		return "Tales and Mythology";
	case Genre::THRILLER:
		return "Thriller";
	case Genre::WAR_MILITARY:
		return "War and Military";
	default:
		return "Other";
	}
}