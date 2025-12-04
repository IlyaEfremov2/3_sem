#include "MusicStore.h"
#include <algorithm>

MusicStore::MusicStore() : totalSales(0) {}

void MusicStore::addCollection(const MusicCollection& collection) {
    collections.push_back(collection);
}

std::vector<MusicCollection> MusicStore::findWorkByTitle(const std::string& title) const {
    std::vector<MusicCollection> result;
    for (const auto& collection : collections) {
        if (collection.getWork()->getTitle() == title) {
            result.push_back(collection);
        }
    }
    return result;
}

std::vector<MusicCollection> MusicStore::findWorkByComposer(const std::string& composer) const {
    std::vector<MusicCollection> result;
    for (const auto& collection : collections) {
        if (collection.getWork()->getComposer() == composer) {
            result.push_back(collection);
        }
    }
    return result;
}

std::vector<MusicCollection> MusicStore::findWorkByGenre(const std::string& genre) const {
    std::vector<MusicCollection> result;
    for (const auto& collection : collections) {
        if (collection.getWork()->getGenre() == genre) {
            result.push_back(collection);
        }
    }
    return result;
}

std::vector<std::string> MusicStore::getAvailableMediaTypes(const std::string& workTitle) const {
    auto works = findWorkByTitle(workTitle);
    if (!works.empty()) {
        return works[0].getAvailableMediaTypes();
    }
    return {};
}

std::vector<MusicCollection> MusicStore::getWorksByGenre(const std::string& genre) const {
    return findWorkByGenre(genre);
}

std::string MusicStore::getWorkInfo(const std::string& workTitle) const {
    auto works = findWorkByTitle(workTitle);
    if (!works.empty()) {
        return works[0].getInfo();
    }
    return "Произведение не найдено";
}

std::vector<std::string> MusicStore::getMostSoldWorks(int count) const {
    std::vector<std::string> popularWorks;
    int actualCount = count;
    if (actualCount > static_cast<int>(collections.size())) {
        actualCount = collections.size();
    }

    for (int i = 0; i < actualCount; i++) {
        popularWorks.push_back(collections[i].getWork()->getTitle());
    }
    return popularWorks;
}

double MusicStore::getSalesForPeriod() const {
    return totalSales;
}

void MusicStore::sellWork(const std::string& workTitle, const std::string& mediaType, int quantity) {
    auto works = findWorkByTitle(workTitle);
    if (!works.empty()) {
        totalSales += works[0].getWork()->getPrice() * quantity;
    }
}