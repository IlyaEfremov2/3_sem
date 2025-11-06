#pragma once
#include "Generator.h"

namespace miit::algebra
{
    /**
    * @brief Генератор постоянных значений
    */
    class ConstantGenerator : public Generator
    {
    private:
        int constant_value;

    public:
        ConstantGenerator(int value);
        int generate() override;
    };
}