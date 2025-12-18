#pragma once
#include <string>
#include <vector>
#include <memory>

class MusicWork; 
class MusicStore;

class MusicStorage {
private:
    std::string mediaType;
    std::string location;
    int quantity;
    std::vector<std::shared_ptr<MusicWork>> storedWorks; 
    std::vector<MusicStore*> stores;

public:
    MusicStorage(const std::string& mediaType, const std::string& location, int quantity);
    std::string getMediaType() const;
    std::string getLocation() const;
    int getQuantity() const;
    std::string getInfo() const;
    std::vector<std::shared_ptr<MusicWork>> getStoredWorks() const;
    void addWork(const std::shared_ptr<MusicWork>& work);
    void removeWork(const std::shared_ptr<MusicWork>& work);
    bool containsWork(const std::shared_ptr<MusicWork>& work) const;
    int getWorksCount() const;
    std::string getWorksInfo() const;
};