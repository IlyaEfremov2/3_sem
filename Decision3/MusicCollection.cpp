#include "MusicCollection.h"

MusicCollection::MusicCollection(std::shared_ptr<MusicWork> work) : work(work) {}

void MusicCollection::addStorage(const MusicStorage& storage) {
    availableStorages.push_back(storage);
}

std::shared_ptr<MusicWork> MusicCollection::getWork() const {
    return work;
}

std::vector<std::string> MusicCollection::getAvailableMediaTypes() const {
    std::vector<std::string> mediaTypes;
    for (const auto& storage : availableStorages) {
        mediaTypes.push_back(storage.getMediaType());
    }
    return mediaTypes;
}

std::string MusicCollection::getInfo() const {
    std::string info = work->getInfo() + "\nДоступные носители: ";
    for (const auto& storage : availableStorages) {
        info += storage.getMediaType() + " ";
    }
    return info;
}