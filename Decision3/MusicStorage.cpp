#include "MusicStorage.h"
#include "MusicWork.h"
#include <algorithm>

MusicStorage::MusicStorage(MusicStore* store, const std::string& mediaType, const std::string& location, int quantity) : store(store), mediaType(mediaType), location(location), quantity(quantity)
{
}

std::string MusicStorage::getMediaType() const {
    return mediaType;
}

std::string MusicStorage::getLocation() const {
    return location;
}

int MusicStorage::getQuantity() const {
    return quantity;
}

std::string MusicStorage::getInfo() const {
    return "Носитель: " + mediaType +
        ", Местоположение: " + location +
        ", Количество: " + std::to_string(quantity) +
        ", Произведений: " + std::to_string(storedWorks.size());
}

std::vector<std::shared_ptr<MusicWork>> MusicStorage::getStoredWorks() const {
    return storedWorks;
}

void MusicStorage::addWork(const std::shared_ptr<MusicWork>& work) {
    if (work && !containsWork(work)) {
        storedWorks.push_back(work);
        work->addMediaCarrier(*this);
    }
}

void MusicStorage::removeWork(const std::shared_ptr<MusicWork>& work) {
    if (!work) return;

    auto it = std::find(storedWorks.begin(), storedWorks.end(), work);
    if (it != storedWorks.end()) {
        storedWorks.erase(it);
        work->removeMediaCarrier(*this);
    }
}

bool MusicStorage::containsWork(const std::shared_ptr<MusicWork>& work) const {
    return std::find(storedWorks.begin(), storedWorks.end(), work) != storedWorks.end();
}

int MusicStorage::getWorksCount() const {
    return static_cast<int>(storedWorks.size());
}

std::string MusicStorage::getWorksInfo() const {
    if (storedWorks.empty()) {
        return "На носителе нет произведений";
    }

    std::string info = "Содержит произведения: ";
    for (const auto& work : storedWorks) {
        if (work) {
            info += work->getTitle() + " (" + work->getComposer() + "), ";
        }
    }
    if (!storedWorks.empty()) {
        info = info.substr(0, info.length() - 2);
    }
    return info;
}