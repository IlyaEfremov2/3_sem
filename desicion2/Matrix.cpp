#include "Matrix.h"
#include "Generator.h"
#include <sstream>
#include <algorithm>

namespace miit::algebra
{
    Matrix::Matrix() : data{ std::make_unique<std::vector<int>>() } {}

    Matrix::Matrix(size_t size) : data{ std::make_unique<std::vector<int>>(size) } {}

    Matrix::Matrix(size_t size, int value) : data{ std::make_unique<std::vector<int>>(size, value) } {}

    Matrix::Matrix(const Matrix& other)
        : data{ std::make_unique<std::vector<int>>(*other.data) } {}

    Matrix::Matrix(Matrix&& other) noexcept
        : data{ std::move(other.data) } {}

    Matrix& Matrix::operator=(const Matrix& other)
    {
        if (this != &other)
        {
            data = std::make_unique<std::vector<int>>(*other.data);
        }
        return *this;
    }

    Matrix& Matrix::operator=(Matrix&& other) noexcept
    {
        if (this != &other)
        {
            data = std::move(other.data);
        }
        return *this;
    }

    Matrix Matrix::operator<<(size_t positions) const
    {
        Matrix result(*this);
        if (!result.data->empty())
        {
            positions %= result.data->size();
            std::rotate(result.data->begin(), result.data->begin() + positions, result.data->end());
        }
        return result;
    }

    Matrix Matrix::operator>>(size_t positions) const
    {
        Matrix result(*this);
        if (!result.data->empty())
        {
            positions %= result.data->size();
            std::rotate(result.data->rbegin(), result.data->rbegin() + positions, result.data->rend());
        }
        return result;
    }

    int& Matrix::operator[](size_t index)
    {
        return (*data)[index];
    }

    const int& Matrix::operator[](size_t index) const
    {
        return (*data)[index];
    }

    int* Matrix::operator*()
    {
        return data->data();
    }

    const int* Matrix::operator*() const
    {
        return data->data();
    }

    size_t Matrix::size() const
    {
        return data->size();
    }

    std::string Matrix::to_string() const
    {
        std::ostringstream oss;
        oss << "[";
        for (size_t i = 0; i < data->size(); ++i)
        {
            oss << (*data)[i];
            if (i < data->size() - 1)
            {
                oss << ", ";
            }
        }
        oss << "]";
        return oss.str();
    }

    void Matrix::fill(std::unique_ptr<Generator> generator)
    {
        for (size_t i = 0; i < data->size(); ++i)
        {
            (*data)[i] = generator->generate();
        }
    }

    void Matrix::fill_zeros()
    {
        std::fill(data->begin(), data->end(), 0);
    }

    void Matrix::fill_constant(int value)
    {
        std::fill(data->begin(), data->end(), value);
    }
}