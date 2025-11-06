#pragma once
#include <memory>

namespace miit::algebra
{
    /**
    * @brief Абстрактный класс для генерации данных
    */
    class Generator
    {
    public:
        virtual ~Generator() = default;

        /**
        * @brief Генерирует следующее значение
        * @return сгенерированное значение
        */
        virtual int generate() = 0;
    };
}