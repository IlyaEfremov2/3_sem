#include "Exercise.h"

namespace miit::algebra
{
    Exercise::Exercise(std::unique_ptr<Matrix> matrix, std::unique_ptr<Generator> generator)
        : matrix{ std::move(matrix) }
        , generator{ std::move(generator) }
    {
    }

    const Matrix& Exercise::get_matrix() const
    {
        return *matrix;
    }
}