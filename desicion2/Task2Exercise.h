#pragma once

#include "Exercise.h"

namespace miit::algebra
{
    /**
    * @brief Реализация задания 2: Фильтрация элементов с четными первой и последней цифрами
    */
    class Task2Exercise : public Exercise
    {
    private:
        /**
        * @brief Проверяет, что первая и последняя цифры числа четные
        * @param value число для проверки
        * @return true если обе цифры четные
        */
        bool check_digits(int value) const;

    public:
        using Exercise::Exercise;

        std::unique_ptr<Matrix> Task2() override;
    };
}