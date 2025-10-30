#include "Task1Exercise.h"
#include <algorithm>
#include <limits>

namespace miit::algebra
{
    void Task1Exercise::execute()
    {
        int min_positive = std::numeric_limits<int>::max();
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

}