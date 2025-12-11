#pragma once
#include <string>
#include <vector>
#include <memory>

class MusicStorage;  // Предварительное объявление

class MusicWork {
private:
    std::string title;
    std::string composer;
    std::string genre;
    int year;
    std::string album;
    double price;
    std::vector<MusicStorage> mediaCarriers;

public:
    MusicWork(const std::string& title, const std::string& composer, const std::string& genre,
        int year, const std::string& album, double price);

    virtual ~MusicWork() = default;

    std::string getTitle() const;
    std::string getComposer() const;
    std::string getGenre() const;
    int getYear() const;
    std::string getAlbum() const;
    virtual double getPrice() const;
    virtual std::string getInfo() const;
    std::vector<MusicStorage> getMediaCarriers() const;
    void addMediaCarrier(const MusicStorage& carrier);
    void removeMediaCarrier(const MusicStorage& carrier);
    bool hasMediaCarrier(const std::string& mediaType) const;
    std::vector<std::string> getAvailableMediaTypes() const;
    std::string getMediaCarriersInfo() const;
    int getMediaCarriersCount() const;
};