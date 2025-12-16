#pragma once
#include "MusicWork.h"
#include "MusicStorage.h"
#include <vector>
#include <memory>
#include <string>

class MusicItem {
private:
    std::shared_ptr<MusicWork> work;
    std::vector<MusicStorage> availableStorages;
    int soldCount;

public:
    explicit MusicItem(std::shared_ptr<MusicWork> work);
    void addStorage(const MusicStorage& storage);
    std::shared_ptr<MusicWork> getWork() const;
    std::vector<std::string> getAvailableMediaTypes() const;
    std::string getInfo() const;
    int getSoldCount() const;
    void increaseSoldCount(int quantity);
    const std::vector<MusicStorage>& getStorages() const;
};

class MusicStore {
private:
    std::vector<MusicItem> musicItems;
    double totalSales;

public:
    std::vector<std::shared_ptr<MusicWork>> getAllWorks() const;
    bool addStorageToWork(const std::string& workTitle, const MusicStorage& storage);
    void addStorageToStore(const MusicStorage& storage);
    MusicStore();
    void addStorageToStore(const MusicStorage& storage);
    void registerStorageWithAllWorks(const MusicStorage& storage);
    void addMusicItem(const MusicItem& item);
    std::vector<MusicItem> findWorkByTitle(const std::string& title) const;
    std::vector<MusicItem> findWorkByComposer(const std::string& composer) const;
    std::vector<MusicItem> findWorkByGenre(const std::string& genre) const;
    std::vector<std::string> getAvailableMediaTypes(const std::string& workTitle) const;
    std::vector<MusicItem> getWorksByGenre(const std::string& genre) const;
    std::string getWorkInfo(const std::string& workTitle) const;
    std::vector<std::string> getMostSoldWorks(int count) const;
    double getSalesForPeriod() const;
    void sellWork(const std::string& workTitle, const std::string& mediaType, int quantity);
    MusicItem* findMusicItem(const std::string& title);
};