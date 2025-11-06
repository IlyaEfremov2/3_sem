#pragma once

namespace miit::algebra
{
    /**
    * @brief Абстрактный генератор значений для заполнения матрицы
    */
    class Generator
    {
    public:
        /**
        * @brief Виртуальный деструктор
        */
        virtual ~Generator() = default;

        /**
        * @brief Генерирует следующее значение
        * @return сгенерированное значение
        */
        virtual int generate() = 0;
    };

    /**
    * @brief Генератор постоянных значений
    */
    class ConstantGenerator : public Generator
    {
    private:
        int constant_value;  // Значение, которое всегда возвращается

    public:
        /**
        * @brief Конструктор
        * @param value постоянное значение для генерации
        */
        ConstantGenerator(int value) : constant_value(value) {}

        /**
        * @brief Генерирует постоянное значение
        * @return заданное постоянное значение
        */
        int generate() override { return constant_value; }
    };
}