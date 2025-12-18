#include "MusicWork.h"
#include "MusicStorage.h"
#include <algorithm>

MusicWork::MusicWork(const std::string& title, const std::string& composer, const std::string& genre,
    int year, const std::string& album, double price)
    : title(title), composer(composer), genre(genre), year(year), album(album), price(price) {
}

std::string MusicWork::getTitle() const {
    return title;
}

std::string MusicWork::getComposer() const {
    return composer;
}

std::string MusicWork::getGenre() const {
    return genre;
}

int MusicWork::getYear() const {
    return year;
}

std::string MusicWork::getAlbum() const {
    return album;
}

double MusicWork::getPrice() const {
    return price;
}

std::string MusicWork::getInfo() const {
    return "Произведение: " + title +
        " (" + std::to_string(year) + "), " +
        "Композитор: " + composer +
        ", Жанр: " + genre +
        ", Альбом: " + album +
        ", Цена: " + std::to_string(price) + " руб.";
}

std::vector<MusicStorage> MusicWork::getMediaCarriers() const {
    return mediaCarriers;
}

void MusicWork::addMediaCarrier(const MusicStorage& carrier) {
    if (!hasMediaCarrier(carrier.getMediaType())) {
        mediaCarriers.push_back(carrier);
    }
}

void MusicWork::removeMediaCarrier(const MusicStorage& carrier) {
    mediaCarriers.erase(
        std::remove_if(mediaCarriers.begin(), mediaCarriers.end(),
            [&carrier](const MusicStorage& mc) {
                return mc.getMediaType() == carrier.getMediaType();
            }),
        mediaCarriers.end()
    );
}

bool MusicWork::hasMediaCarrier(const std::string& mediaType) const {
    for (const auto& carrier : mediaCarriers) {
        if (carrier.getMediaType() == mediaType) {
            return true;
        }
    }
    return false;
}

std::vector<std::string> MusicWork::getAvailableMediaTypes() const {
    std::vector<std::string> types;
    for (const auto& carrier : mediaCarriers) {
        types.push_back(carrier.getMediaType());
    }
    return types;
}

std::string MusicWork::getMediaCarriersInfo() const {
    if (mediaCarriers.empty()) {
        return "Нет доступных носителей";
    }

    std::string info = "Доступно на носителях: ";
    for (const auto& carrier : mediaCarriers) {
        info += carrier.getMediaType() + " (" + carrier.getLocation() + "), ";
    }
    if (!mediaCarriers.empty()) {
        info = info.substr(0, info.length() - 2);
    }
    return info;
}

int MusicWork::getMediaCarriersCount() const {
    return static_cast<int>(mediaCarriers.size());
}