#pragma once
#include "MusicWork.h"
#include "MusicStorage.h"
#include <vector>
#include <memory>

/**
 * @brief Класс, представляющий коллекцию произведения с доступными носителями
 */
class MusicCollection {
private:
    std::shared_ptr<MusicWork> work;
    std::vector<MusicStorage> availableStorages;

public:
    /**
     * @brief Конструктор коллекции
     * @param work Умный указатель на музыкальное произведение
     */
    explicit MusicCollection(std::shared_ptr<MusicWork> work);

    /**
     * @brief Добавить носитель в коллекцию
     * @param storage Носитель произведения
     */
    void addStorage(const MusicStorage& storage);

    /**
    * @brief Получить произведение коллекции
    */
    std::shared_ptr<MusicWork> getWork() const;

    /**
     * @brief Получить список доступных типов носителей
     * @return Вектор строк с типами носителей
     */
    std::vector<std::string> getAvailableMediaTypes() const;

    /**
     * @brief Получить информацию о коллекции
     * @return Строка с информацией о произведении и носителях
     */
    std::string getInfo() const;
};