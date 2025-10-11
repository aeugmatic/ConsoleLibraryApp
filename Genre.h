#pragma once

#include <string>

enum class Genre {
    ACTION,
    ADVENTURE,
    BIOGRAPHY,
    CLASSICS,
    CRIME,
    DYSTOPIAN,
    EROTICA,
    FANTASY,
    HISTORY,
    HORROR,
    HUMOUR,
    MYSTERY,
    NOIR,
    POLITICS,
    PHILOSOPHY,
    PSYCHOLOGY,
    RELIGION,
    ROMANCE,
    SCIENCE,
    SCIFI,
    SPORTS,
    SUPERNATURAL,
    TALES_MYTHOLOGY,
    THRILLER,
    WAR_MILITARY
};

std::string genreToString(Genre g);