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
        * @brief Выполнение задания
        */
        virtual void execute() = 0;

        /**
        * @brief Получить матрицу
        * @return ссылка на матрицу
        */
        const Matrix& get_matrix() const;
    };
}