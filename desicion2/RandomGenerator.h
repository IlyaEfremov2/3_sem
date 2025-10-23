#pragma once

#include "Generator.h"
#include <random>
#include <memory>

namespace miit::algebra
{
    /**
    * @brief Генератор случайных чисел
    */
    class RandomGenerator : public Generator
    {
    private:
        std::unique_ptr<std::uniform_int_distribution<int>> distribution;
        std::unique_ptr<std::mt19937> generator;

    public:
        /**
        * @brief Конструктор генератора случайных чисел
        * @param min минимальное значение
        * @param max максимальное значение
        */
        RandomGenerator(int min, int max);

        /**
        * @brief Генерирует случайное число
        * @return случайное число в заданном диапазоне
        */
        int generate() override;
    };
}