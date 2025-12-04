#pragma once
#include "MusicCollection.h"
#include <vector>
#include <memory>

/**
 * @brief Основной класс магазина музыкальных произведений
 */
class MusicStore {
private:
    std::vector<MusicCollection> collections;
    double totalSales;

public:
    /**
     * @brief Конструктор магазина
     */
    MusicStore();

    /**
     * @brief Добавить коллекцию в магазин
     * @param collection Коллекция произведений
     */
    void addCollection(const MusicCollection& collection);

    /**
     * @brief Найти произведения по названию
     * @param title Название произведения для поиска
     * @return Вектор найденных коллекций
     */
    std::vector<MusicCollection> findWorkByTitle(const std::string& title) const;

    /**
     * @brief Найти произведения по композитору/исполнителю
     * @param composer Композитор для поиска
     * @return Вектор найденных коллекций
     */
    std::vector<MusicCollection> findWorkByComposer(const std::string& composer) const;

    /**
     * @brief Найти произведения по жанру
     * @param genre Жанр для поиска
     * @return Вектор найденных коллекций
     */
    std::vector<MusicCollection> findWorkByGenre(const std::string& genre) const;

    /**
     * @brief Получить доступные типы носителей для произведения
     * @param workTitle Название произведения
     * @return Вектор строк с типами носителей
     */
    std::vector<std::string> getAvailableMediaTypes(const std::string& workTitle) const;

    /**
     * @brief Получить произведения по жанру
     * @param genre Жанр произведений
     * @return Вектор коллекций произведений указанного жанра
     */
    std::vector<MusicCollection> getWorksByGenre(const std::string& genre) const;

    /**
     * @brief Получить информацию о произведении
     * @param workTitle Название произведения
     * @return Строка с информацией о произведении
     */
    std::string getWorkInfo(const std::string& workTitle) const;

    /**
     * @brief Получить список самых продаваемых произведений
     * @param count Количество произведений в списке
     * @return Вектор названий самых продаваемых произведений
     */
    std::vector<std::string> getMostSoldWorks(int count) const;

    /**
     * @brief Получить общую сумму продаж за период
     * @return Сумма продаж
     */
    double getSalesForPeriod() const;

    /**
     * @brief Продать произведение
     * @param workTitle Название произведения
     * @param mediaType Тип носителя
     * @param quantity Количество для продажи
     */
    void sellWork(const std::string& workTitle, const std::string& mediaType, int quantity);
};