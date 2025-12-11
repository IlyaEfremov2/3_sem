#pragma once
#include "MusicWork.h"
#include "MusicStorage.h"
#include <vector>
#include <memory>
#include <string>

/**
 * @brief Класс для хранения информации о музыкальном произведении и его носителях
 */
    class MusicItem {
    private:
        std::shared_ptr<MusicWork> work;          
        std::vector<MusicStorage> availableStorages; 
        int soldCount;                       

    public:
        /**
         * @brief Конструктор музыкального элемента
         * @param work Умный указатель на музыкальное произведение
         */
        explicit MusicItem(std::shared_ptr<MusicWork> work);

        /**
         * @brief Добавить носитель в коллекцию
         * @param storage Носитель произведения
         */
        void addStorage(const MusicStorage& storage);

        /**
         * @brief Получить произведение
         * @return Умный указатель на произведение
         */
        std::shared_ptr<MusicWork> getWork() const;

        /**
         * @brief Получить список доступных типов носителей
         * @return Вектор строк с типами носителей
         */
        std::vector<std::string> getAvailableMediaTypes() const;

        /**
         * @brief Получить информацию о музыкальном элементе
         * @return Строка с информацией о произведении и носителях
         */
        std::string getInfo() const;

        /**
         * @brief Получить количество проданных копий
         * @return Количество проданных копий
         */
        int getSoldCount() const;

        /**
         * @brief Увеличить количество проданных копий
         * @param quantity Количество для добавления
         */
        void increaseSoldCount(int quantity);

        /**
         * @brief Получить все доступные носители
         * @return Вектор носителей
         */
        const std::vector<MusicStorage>& getStorages() const;
};

/**
 * @brief Основной класс магазина музыкальных произведений
 */
class MusicStore {
private:
    std::vector<MusicItem> musicItems;  
    double totalSales;                  

public:
    /**
     * @brief Конструктор магазина
     */
    MusicStore();

    /**
     * @brief Добавить музыкальный элемент в магазин
     * @param item Музыкальный элемент
     */
    void addMusicItem(const MusicItem& item);

    /**
     * @brief Найти музыкальные элементы по названию
     * @param title Название произведения для поиска
     * @return Вектор найденных музыкальных элементов
     */
    std::vector<MusicItem> findWorkByTitle(const std::string& title) const;

    /**
     * @brief Найти музыкальные элементы по композитору/исполнителю
     * @param composer Композитор для поиска
     * @return Вектор найденных музыкальных элементов
     */
    std::vector<MusicItem> findWorkByComposer(const std::string& composer) const;

    /**
     * @brief Найти музыкальные элементы по жанру
     * @param genre Жанр для поиска
     * @return Вектор найденных музыкальных элементов
     */
    std::vector<MusicItem> findWorkByGenre(const std::string& genre) const;

    /**
     * @brief Получить доступные типы носителей для произведения
     * @param workTitle Название произведения
     * @return Вектор строк с типами носителей
     */
    std::vector<std::string> getAvailableMediaTypes(const std::string& workTitle) const;

    /**
     * @brief Получить произведения по жанру
     * @param genre Жанр произведений
     * @return Вектор музыкальных элементов указанного жанра
     */
    std::vector<MusicItem> getWorksByGenre(const std::string& genre) const;

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

    /**
     * @brief Найти музыкальный элемент по названию (внутренний метод)
     * @param title Название произведения
     * @return Найденный музыкальный элемент или nullptr
     */
    MusicItem* findMusicItem(const std::string& title);
};
