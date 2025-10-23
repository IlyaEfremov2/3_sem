#pragma once

#include "Matrix.h"
#include "Generator.h"
#include <memory>

namespace miit::algebra
{
    /**
    * @brief Абстрактный класс для выполнения заданий
    */
    class Exercise
    {
    protected:
        std::unique_ptr<Matrix> matrix;
        std::unique_ptr<Generator> generator;

    public:
        /**
        * @brief Конструктор
        * @param matrix матрица для работы
        * @param generator генератор значений
        */
        Exercise(std::unique_ptr<Matrix> matrix, std::unique_ptr<Generator> generator);

        /**
        * @brief Виртуальный деструктор
        */
        virtual ~Exercise() = default;

        /**
        * @brief Задание 1: Замена минимального положительного элемента нулем
        */
        virtual void Task1() = 0;

        /**
        * @brief Задание 2: Фильтрация элементов с четными первой и последней цифрами
        * @return новая матрица с отфильтрованными элементами
        */
        virtual std::unique_ptr<Matrix> Task2() = 0;

        /**
        * @brief Задание 3: Преобразование массива по правилу
        */
        virtual void Task3() = 0;

        /**
        * @brief Получить матрицу
        * @return ссылка на матрицу
        */
        const Matrix& get_matrix() const;
    };
}