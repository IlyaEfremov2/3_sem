#pragma once

#include "Generator.h"
#include <iostream>
#include <memory>

namespace miit::algebra
{
    /**
    * @brief Генератор значений из входного потока
    */
    class IStreamGenerator : public Generator
    {
    private:
        std::istream& in;

    public:
        /**
        * @brief Конструктор
        * @param in входной поток (по умолчанию std::cin)
        */
        IStreamGenerator(std::istream& in = std::cin);

        /**
        * @brief Читает значение из входного потока
        * @return прочитанное значение
        */
        int generate() override;
    };
}