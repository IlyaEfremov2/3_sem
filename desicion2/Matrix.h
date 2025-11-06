#pragma once

#include <vector>
#include <memory>
#include <string>

namespace miit::algebra
{
    // Forward declaration чтобы избежать циклического включения
    class Generator;

    /**
    * @brief Одномерная матрица (массив) с операциями
    */
    class Matrix
    {
    private:
        std::unique_ptr<std::vector<int>> data;

    public:
        /**
        * @brief Конструктор по умолчанию
        */
        Matrix();

        /**
        * @brief Конструктор с размером
        * @param size размер матрицы
        */
        explicit Matrix(size_t size);

        /**
        * @brief Конструктор с размером и значением по умолчанию
        * @param size размер матрицы
        * @param value значение по умолчанию
        */
        Matrix(size_t size, int value);

        /**
        * @brief Конструктор копирования
        * @param other другая матрица
        */
        Matrix(const Matrix& other);

        /**
        * @brief Конструктор перемещения
        * @param other другая матрица
        */
        Matrix(Matrix&& other) noexcept;

        /**
        * @brief Деструктор
        */
        ~Matrix() = default;

        /**
        * @brief Оператор присваивания копированием
        * @param other другая матрица
        * @return ссылка на текущую матрицу
        */
        Matrix& operator=(const Matrix& other);

        /**
        * @brief Оператор присваивания перемещением
        * @param other другая матрица
        * @return ссылка на текущую матрицу
        */
        Matrix& operator=(Matrix&& other) noexcept;

        /**
        * @brief Оператор сдвига влево
        * @param positions количество позиций для сдвига
        * @return новая матрица
        */
        Matrix operator<<(size_t positions) const;

        /**
        * @brief Оператор сдвига вправо
        * @param positions количество позиций для сдвига
        * @return новая матрица
        */
        Matrix operator>>(size_t positions) const;

        /**
        * @brief Оператор доступа по индексу
        * @param index индекс элемента
        * @return ссылка на элемент
        */
        int& operator[](size_t index);

        /**
        * @brief Константный оператор доступа по индексу
        * @param index индекс элемента
        * @return константная ссылка на элемент
        */
        const int& operator[](size_t index) const;

        /**
        * @brief Оператор разыменования
        * @return указатель на данные
        */
        int* operator*();

        /**
        * @brief Константный оператор разыменования
        * @return константный указатель на данные
        */
        const int* operator*() const;

        /**
        * @brief Получить размер матрицы
        * @return размер матрицы
        */
        size_t size() const;

        /**
        * @brief Получить строковое представление матрицы
        * @return строка с содержимым матрицы
        */
        std::string to_string() const;

        /**
        * @brief Заполнить матрицу с помощью генератора
        * @param generator генератор значений
        */
        void fill(std::unique_ptr<Generator> generator);
    };
}