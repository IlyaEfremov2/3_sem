#include "Task3Exercise.h"
#include <cmath>
#include <iostream>

namespace miit::algebra
{
    void Task3Exercise::execute()
    {

        for (size_t i = 0; i < matrix->size(); ++i)
        {
            if (i >= 2 && i <= 11) // Элементы с 3-го по 12-й (индексы 2-11)
            {
                int original = (*matrix)[i];
                (*matrix)[i] = -static_cast<int>(std::pow((*matrix)[i], 2));
            }
            else
            {
                int original = (*matrix)[i];
                (*matrix)[i] = (*matrix)[i] - 1;

            }
        }
        std::cout << "3 задание: " << matrix->to_string() << std::endl;
        std::cout << std::endl;
    }
}