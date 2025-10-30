#pragma once

#include "Exercise.h"

namespace miit::algebra
{
    /**
    * @brief Реализация задания 1: Замена минимального положительного элемента нулем
    */
    class Task1Exercise : public Exercise
    {
    public:
        using Exercise::Exercise;

        void execute() override;
    };
}