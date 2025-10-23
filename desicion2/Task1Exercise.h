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

        void Task1() override;
        std::unique_ptr<Matrix> Task2() override;
        void Task3() override;
    };
}