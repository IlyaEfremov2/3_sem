#include "Task3Exercise.h"
#include <cmath>

namespace miit::algebra
{
    void Task3Exercise::Task3()
    {
        for (size_t i = 0; i < matrix->size(); ++i)
        {
            if (i >= 2 && i <= 11) // Элементы с 3-го по 12-й (индексы 2-11)
            {
                (*matrix)[i] = -static_cast<int>(std::pow((*matrix)[i], 2));
            }
            else
            {
                (*matrix)[i] = (*matrix)[i] - 1;
            }
        }
    }
}