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

    void Task2Exercise::execute()
    {
        // Создаем временный вектор для отфильтрованных элементов
        std::vector<int> filtered_elements;

        // Фильтруем элементы с четными первой и последней цифрами
        for (size_t i = 0; i < matrix->size(); ++i)
        {
            if (check_digits((*matrix)[i]))
            {
                filtered_elements.push_back((*matrix)[i]);
            }
        }

        // Заменяем данные текущей матрицы на отфильтрованные
        *matrix = Matrix(filtered_elements.size());
        for (size_t i = 0; i < filtered_elements.size(); ++i)
        {
            (*matrix)[i] = filtered_elements[i];
        }
    }
}