#include "Task1Exercise.h"
#include <algorithm>
#include <climits>

namespace miit::algebra
{
    void Task1Exercise::Task1()
    {
        int min_positive = INT_MAX;
        int min_index = -1;

        for (size_t i = 0; i < matrix->size(); ++i)
        {
            int current = (*matrix)[i];
            if (current > 0 && current < min_positive)
            {
                min_positive = current;
                min_index = static_cast<int>(i);
            }
        }

        if (min_index != -1)
        {
            (*matrix)[min_index] = 0;
        }
    }

    std::unique_ptr<Matrix> Task1Exercise::Task2()
    {
        // Для Task1Exercise Task2 не реализован
        return std::make_unique<Matrix>(*matrix);
    }

    void Task1Exercise::Task3()
    {
        // Для Task1Exercise Task3 не реализован
    }
}