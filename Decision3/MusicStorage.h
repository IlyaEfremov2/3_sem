#pragma once
#include <string>
#include <memory>

/**
 * @brief Класс, представляющий носитель музыкального произведения
 */
class MusicStorage {
private:
    std::string mediaType;  
    std::string location;
    int quantity;

public:
    /**
     * @brief Конструктор носителя
     * @param mediaType Тип носителя
     * @param location Местоположение
     * @param quantity Количество
     */
    MusicStorage(const std::string& mediaType, const std::string& location, int quantity);

    /**
    * @brief Получить тип носителя
    */
    std::string getMediaType() const;

    /**
    * @brief Получить местоположение
    */
    std::string getLocation() const;

    /**
    * @brief Получить количество
    */
    int getQuantity() const;

    /**
     * @brief Получить информацию о носителе
     * @return Строка с информацией
     */
    std::string getInfo() const;
};