#include "MusicStorage.h"

MusicStorage::MusicStorage(const std::string& mediaType, const std::string& location, int quantity)
    : mediaType(mediaType), location(location), quantity(quantity) {
}

std::string MusicStorage::getMediaType() const { return mediaType; }
std::string MusicStorage::getLocation() const { return location; }
int MusicStorage::getQuantity() const { return quantity; }

std::string MusicStorage::getInfo() const {
    return "Носитель: " + mediaType +
        ", Местоположение: " + location +
        ", Количество: " + std::to_string(quantity);
}