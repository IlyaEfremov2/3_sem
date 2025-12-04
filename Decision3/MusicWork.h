#pragma once
#include <string>
#include <vector>
#include <memory>

/**
 * @brief Базовый класс, представляющий музыкальное произведение
 */
class MusicWork {
private:
    std::string title;
    std::string composer;
    std::string genre;
    int year;
    std::string album;
    double price;

public:
    /**
     * @brief Конструктор музыкального произведения
     * @param title Название произведения
     * @param composer Композитор/исполнитель
     * @param genre Жанр
     * @param year Год выпуска
     * @param album Альбом
     * @param price Цена
     */
    MusicWork(const std::string& title, const std::string& composer, const std::string& genre,
        int year, const std::string& album, double price);

    virtual ~MusicWork() = default;

    /**
    * @brief Получить название произведения
    */
    std::string getTitle() const;

    /**
    * @brief Получить композитора/исполнителя
    */
    std::string getComposer() const;

    /**
    * @brief Получить жанр
    */
    std::string getGenre() const;

    /**
    * @brief Получить год выпуска
    */
    int getYear() const;

    /**
    * @brief Получить альбом
    */
    std::string getAlbum() const;

    /**
    * @brief Получить цену
    */
    virtual double getPrice() const;

    /**
     * @brief Получить информацию о произведении
     * @return Строка с информацией о произведении
     */
    virtual std::string getInfo() const;
};