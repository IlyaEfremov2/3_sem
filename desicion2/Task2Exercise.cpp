#include "Task2Exercise.h"
#include <cmath>

namespace miit::algebra
{
    bool Task2Exercise::check_digits(int value) const
    {
        value = std::abs(value);
        int last_digit = value % 10;

        int first_digit = value;
        while (first_digit >= 10)
        {
            first_digit /= 10;
        }

        return (first_digit % 2 == 0) && (last_digit % 2 == 0);
    }

    void Task2Exercise::Task1()
    {
        // Для Task2Exercise Task1 не реализован
    }

    std::unique_ptr<Matrix> Task2Exercise::Task2()
    {
        size_t new_size = 0;

        // Подсчитываем количество подходящих элементов
        for (size_t i = 0; i < matrix->size(); ++i)
        {
            if (check_digits((*matrix)[i]))
            {
                new_size++;
            }
        }

        // Создаем новую матрицу
        auto result = std::make_unique<Matrix>(new_size);
        size_t index = 0;

        // Заполняем новую матрицу
        for (size_t i = 0; i < matrix->size(); ++i)
        {
            if (check_digits((*matrix)[i]))
            {
                (*result)[index++] = (*matrix)[i];
            }
        }

        return result;
    }

    void Task2Exercise::Task3()
    {
        // Для Task2Exercise Task3 не реализован
    }
}