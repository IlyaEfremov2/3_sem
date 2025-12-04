#include "MusicWork.h"

MusicWork::MusicWork(const std::string& title, const std::string& composer, const std::string& genre,
    int year, const std::string& album, double price)
    : title(title), composer(composer), genre(genre), year(year), album(album), price(price) {
}

std::string MusicWork::getTitle() const { return title; }
std::string MusicWork::getComposer() const { return composer; }
std::string MusicWork::getGenre() const { return genre; }
int MusicWork::getYear() const { return year; }
std::string MusicWork::getAlbum() const { return album; }
double MusicWork::getPrice() const { return price; }

std::string MusicWork::getInfo() const {
    return "Произведение: " + title +
        " (" + std::to_string(year) + "), " +
        "Композитор: " + composer +
        ", Жанр: " + genre +
        ", Альбом: " + album +
        ", Цена: " + std::to_string(price) + " руб.";
}