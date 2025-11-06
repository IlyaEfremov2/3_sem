#include "Task2Exercise.h"
#include <cmath>
#include <iostream>

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
        std::vector<int> filtered_elements;

        for (size_t i = 0; i < matrix->size(); ++i)
        {
            if (check_digits((*matrix)[i]))
            {
                filtered_elements.push_back((*matrix)[i]);
            }
        }

        size_t filtered_count = filtered_elements.size();

        *matrix = Matrix(filtered_elements.size());
        for (size_t i = 0; i < filtered_elements.size(); ++i)
        {
            (*matrix)[i] = filtered_elements[i];
        }

        std::cout << "2 задание: " << matrix->to_string() << std::endl;
        std::cout << std::endl;
    }
}