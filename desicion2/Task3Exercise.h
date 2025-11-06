#pragma once

#include "Exercise.h"

namespace miit::algebra
{
    /**
    * @brief Реализация задания 3: Преобразование массива по правилу
    */
    class Task3Exercise : public Exercise
    {
    public:
        using Exercise::Exercise;

        void execute() override;
    };
}