#include "MusicStore.h"
#include <algorithm>
#include <stdexcept>

MusicItem::MusicItem(std::shared_ptr<MusicWork> work)
    : work(work), soldCount(0) {}

void MusicItem::addStorage(const MusicStorage& storage) {
    availableStorages.push_back(storage);
}
void MusicStore::addStorageToStore(const MusicStorage& storage) {
    storage.push_back(storage);
}

void MusicStore::registerStorageWithAllWorks(const MusicStorage& storage) {
 
}


std::shared_ptr<MusicWork> MusicItem::getWork() const {
    return work;
}

std::vector<std::string> MusicItem::getAvailableMediaTypes() const {
    std::vector<std::string> mediaTypes;
    for (const auto& storage : availableStorages) {
        mediaTypes.push_back(storage.getMediaType());
    }
    return mediaTypes;
}

std::string MusicItem::getInfo() const {
    if (!work) return "Пустой музыкальный элемент";

    std::string info = work->getInfo() + "\nДоступные носители: ";
    for (const auto& storage : availableStorages) {
        info += storage.getMediaType() + " ";
    }
    info += "\nПродано копий: " + std::to_string(soldCount);
    return info;
}

int MusicItem::getSoldCount() const {
    return soldCount;
}

void MusicItem::increaseSoldCount(int quantity) {
    if (quantity > 0) {
        soldCount += quantity;
    }
}

const std::vector<MusicStorage>& MusicItem::getStorages() const {
    return availableStorages;
}

MusicStore::MusicStore() : totalSales(0) {}

void MusicStore::addMusicItem(const MusicItem& item) {
    musicItems.push_back(item);
}

std::vector<MusicItem> MusicStore::findWorkByTitle(const std::string& title) const {
    std::vector<MusicItem> result;
    for (const auto& item : musicItems) {
        if (item.getWork()->getTitle() == title) {
            result.push_back(item);
        }
    }
    return result;
}

std::vector<MusicItem> MusicStore::findWorkByComposer(const std::string& composer) const {
    std::vector<MusicItem> result;
    for (const auto& item : musicItems) {
        if (item.getWork()->getComposer() == composer) {
            result.push_back(item);
        }
    }
    return result;
}

std::vector<MusicItem> MusicStore::findWorkByGenre(const std::string& genre) const {
    std::vector<MusicItem> result;
    for (const auto& item : musicItems) {
        if (item.getWork()->getGenre() == genre) {
            result.push_back(item);
        }
    }
    return result;
}

std::vector<std::string> MusicStore::getAvailableMediaTypes(const std::string& workTitle) const {
    auto items = findWorkByTitle(workTitle);
    if (!items.empty()) {
        return items[0].getAvailableMediaTypes();
    }
    return {};
}

std::vector<MusicItem> MusicStore::getWorksByGenre(const std::string& genre) const {
    return findWorkByGenre(genre);
}

std::string MusicStore::getWorkInfo(const std::string& workTitle) const {
    auto items = findWorkByTitle(workTitle);
    if (!items.empty()) {
        return items[0].getInfo();
    }
    return "Произведение не найдено";
}

std::vector<std::string> MusicStore::getMostSoldWorks(int count) const {
    std::vector<MusicItem> sortedItems = musicItems;
    std::sort(sortedItems.begin(), sortedItems.end(),
        [](const MusicItem& a, const MusicItem& b) {
            return a.getSoldCount() > b.getSoldCount();
        });

    std::vector<std::string> result;
    int actualCount = std::min(count, static_cast<int>(sortedItems.size()));
    for (int i = 0; i < actualCount; i++) {
        if (sortedItems[i].getWork()) {
            result.push_back(sortedItems[i].getWork()->getTitle());
        }
    }
    return result;
}

double MusicStore::getSalesForPeriod() const {
    return totalSales;
}

void MusicStore::sellWork(const std::string& workTitle, const std::string& mediaType, int quantity) {
    if (quantity <= 0) {
        throw std::invalid_argument("Количество должно быть положительным");
    }

    auto items = findWorkByTitle(workTitle);
    if (!items.empty()) {
        for (auto& item : musicItems) {
            if (item.getWork()->getTitle() == workTitle) {
                bool mediaAvailable = false;
                for (const auto& storage : item.getStorages()) {
                    if (storage.getMediaType() == mediaType) {
                        mediaAvailable = true;
                        break;
                    }
                }

                if (mediaAvailable) {
                    double price = item.getWork()->getPrice();
                    totalSales += price * quantity;
                    item.increaseSoldCount(quantity);
                    return;
                }
                else {
                    throw std::runtime_error("Тип носителя '" + mediaType + "' не доступен для произведения '" + workTitle + "'");
                }
            }
        }
    }
    throw std::runtime_error("Произведение '" + workTitle + "' не найдено");
}

MusicItem* MusicStore::findMusicItem(const std::string& title) {
    for (auto& item : musicItems) {
        if (item.getWork()->getTitle() == title) {
            return &item;
        }
    }
    return nullptr;
}