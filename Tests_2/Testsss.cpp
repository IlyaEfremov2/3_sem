#include "CppUnitTest.h"
#include "../desicion2/Matrix.h"
#include "../desicion2/RandomGenerator.h"
#include "../desicion2/IStreamGenerator.h"
#include "../desicion2/Task1Exercise.h"
#include "../desicion2/Task2Exercise.h"
#include "../desicion2/Task3Exercise.h"
#include <sstream>
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace miit::algebra;

namespace MatrixUnitTests
{
    TEST_CLASS(MatrixTests)
    {
    public:

        TEST_METHOD(TestDefaultConstructor)
        {
            Matrix matrix;
            Assert::AreEqual(size_t(0), matrix.size());
        }

        TEST_METHOD(TestSizeConstructor)
        {
            Matrix matrix(5);
            Assert::AreEqual(size_t(5), matrix.size());
        }

        TEST_METHOD(TestSizeValueConstructor)
        {
            Matrix matrix(5, 42);
            Assert::AreEqual(size_t(5), matrix.size());
            for (size_t i = 0; i < matrix.size(); ++i)
            {
                Assert::AreEqual(42, matrix[i]);
            }
        }

        TEST_METHOD(TestCopyConstructor)
        {
            Matrix original(3);
            original[0] = 1;
            original[1] = 2;
            original[2] = 3;

            Matrix copy(original);

            Assert::AreEqual(original.size(), copy.size());
            Assert::AreEqual(1, copy[0]);
            Assert::AreEqual(2, copy[1]);
            Assert::AreEqual(3, copy[2]);
        }

        TEST_METHOD(TestIndexOperator)
        {
            Matrix matrix(3);
            matrix[0] = 100;
            matrix[1] = 200;
            matrix[2] = 300;

            Assert::AreEqual(100, matrix[0]);
            Assert::AreEqual(200, matrix[1]);
            Assert::AreEqual(300, matrix[2]);
        }

        TEST_METHOD(TestConstIndexOperator)
        {
            Matrix temp(3);
            temp[0] = 100;
            temp[1] = 200;
            temp[2] = 300;
            const Matrix& matrix = temp;

            Assert::AreEqual(100, matrix[0]);
            Assert::AreEqual(200, matrix[1]);
            Assert::AreEqual(300, matrix[2]);
        }

        TEST_METHOD(TestDereferenceOperator)
        {
            Matrix matrix(3);
            matrix[0] = 5;
            matrix[1] = 6;
            matrix[2] = 7;

            int* data = *matrix;

            Assert::AreEqual(5, data[0]);
            Assert::AreEqual(6, data[1]);
            Assert::AreEqual(7, data[2]);
        }

        TEST_METHOD(TestShiftLeft)
        {
            Matrix matrix(5);
            for (int i = 0; i < 5; ++i) {
                matrix[i] = i + 1;
            }

            Matrix shifted = matrix << 2;

            Assert::AreEqual(3, shifted[0]);
            Assert::AreEqual(4, shifted[1]);
            Assert::AreEqual(5, shifted[2]);
            Assert::AreEqual(1, shifted[3]);
            Assert::AreEqual(2, shifted[4]);
        }

        TEST_METHOD(TestShiftRight)
        {
            Matrix matrix(5);
            for (int i = 0; i < 5; ++i) {
                matrix[i] = i + 1;
            }

            Matrix shifted = matrix >> 2;

            Assert::AreEqual(4, shifted[0]);
            Assert::AreEqual(5, shifted[1]);
            Assert::AreEqual(1, shifted[2]);
            Assert::AreEqual(2, shifted[3]);
            Assert::AreEqual(3, shifted[4]);
        }

        TEST_METHOD(TestToString)
        {
            Matrix matrix(3);
            matrix[0] = 1;
            matrix[1] = 2;
            matrix[2] = 3;

            std::string result = matrix.to_string();
            Assert::AreEqual(std::string("[1, 2, 3]"), result);
        }

        TEST_METHOD(TestToStringEmpty)
        {
            Matrix matrix;
            std::string result = matrix.to_string();
            Assert::AreEqual(std::string("[]"), result);
        }

        TEST_METHOD(TestFillZeros)
        {
            Matrix matrix(5);
            matrix.fill_zeros();

            for (size_t i = 0; i < matrix.size(); ++i) {
                Assert::AreEqual(0, matrix[i]);
            }
        }

        TEST_METHOD(TestFillConstant)
        {
            Matrix matrix(5);
            matrix.fill_constant(42);

            for (size_t i = 0; i < matrix.size(); ++i) {
                Assert::AreEqual(42, matrix[i]);
            }
        }

        TEST_METHOD(TestFillWithGenerator)
        {
            Matrix matrix(5);
            auto generator = std::make_unique<RandomGenerator>(10, 10);
            matrix.fill(std::move(generator));

            for (size_t i = 0; i < matrix.size(); ++i) {
                Assert::AreEqual(10, matrix[i]);
            }
        }
    };

    TEST_CLASS(GeneratorTests)
    {
    public:

        TEST_METHOD(TestRandomGenerator)
        {
            RandomGenerator generator(10, 10);
            int value = generator.generate();
            Assert::AreEqual(10, value);
        }

        TEST_METHOD(TestIStreamGenerator)
        {
            std::istringstream input_stream("42 100 -5");
            IStreamGenerator generator(input_stream);

            Assert::AreEqual(42, generator.generate());
            Assert::AreEqual(100, generator.generate());
            Assert::AreEqual(-5, generator.generate());
        }
    };

    TEST_CLASS(Task1ExerciseTests)
    {
    public:

        TEST_METHOD(TestTask1_ReplaceMinPositive)
        {
            auto matrix = std::make_unique<Matrix>(5);
            (*matrix)[0] = 5;
            (*matrix)[1] = -3;
            (*matrix)[2] = 2;
            (*matrix)[3] = 8;
            (*matrix)[4] = 1;

            auto generator = std::make_unique<RandomGenerator>(1, 10);
            Task1Exercise exercise(std::move(matrix), std::move(generator));

            exercise.Task1();

            const Matrix& result = exercise.get_matrix();
            Assert::AreEqual(0, result[4]);
        }

        TEST_METHOD(TestTask1_NoPositiveElements)
        {
            auto matrix = std::make_unique<Matrix>(3);
            (*matrix)[0] = -5;
            (*matrix)[1] = -3;
            (*matrix)[2] = -1;

            auto generator = std::make_unique<RandomGenerator>(1, 10);
            Task1Exercise exercise(std::move(matrix), std::move(generator));

            exercise.Task1();

            const Matrix& result = exercise.get_matrix();
            Assert::AreEqual(-5, result[0]);
            Assert::AreEqual(-3, result[1]);
            Assert::AreEqual(-1, result[2]);
        }

        TEST_METHOD(TestTask1_SinglePositive)
        {
            auto matrix = std::make_unique<Matrix>(1);
            (*matrix)[0] = 7;

            auto generator = std::make_unique<RandomGenerator>(1, 10);
            Task1Exercise exercise(std::move(matrix), std::move(generator));

            exercise.Task1();

            const Matrix& result = exercise.get_matrix();
            Assert::AreEqual(0, result[0]);
        }
    };

    TEST_CLASS(Task2ExerciseTests)
    {
    public:

        TEST_METHOD(TestTask2_FilterEvenDigits)
        {
            auto matrix = std::make_unique<Matrix>(6);
            (*matrix)[0] = 2468;  
            (*matrix)[1] = 1357;  
            (*matrix)[2] = 42;    
            (*matrix)[3] = 3579;  
            (*matrix)[4] = 2004;  
            (*matrix)[5] = 1234;

            auto generator = std::make_unique<RandomGenerator>(1, 10);
            Task2Exercise exercise(std::move(matrix), std::move(generator));

            auto result = exercise.Task2();

            Assert::AreEqual(size_t(3), result->size());
            Assert::AreEqual(2468, (*result)[0]);
            Assert::AreEqual(42, (*result)[1]);
            Assert::AreEqual(2004, (*result)[2]);
        }

        TEST_METHOD(TestTask2_EmptyResult)
        {
            auto matrix = std::make_unique<Matrix>(3);
            (*matrix)[0] = 1357;
            (*matrix)[1] = 3579;
            (*matrix)[2] = 1234;

            auto generator = std::make_unique<RandomGenerator>(1, 10);
            Task2Exercise exercise(std::move(matrix), std::move(generator));

            auto result = exercise.Task2();
            Assert::AreEqual(size_t(0), result->size());
        }

        TEST_METHOD(TestTask2_SingleDigitEven)
        {
            auto matrix = std::make_unique<Matrix>(4);
            (*matrix)[0] = 2;
            (*matrix)[1] = 4;
            (*matrix)[2] = 6;
            (*matrix)[3] = 8;

            auto generator = std::make_unique<RandomGenerator>(1, 10);
            Task2Exercise exercise(std::move(matrix), std::move(generator));

            auto result = exercise.Task2();
            Assert::AreEqual(size_t(4), result->size());
        }
    };

    TEST_CLASS(Task3ExerciseTests)
    {
    public:

        TEST_METHOD(TestTask3_TransformElements)
        {
            auto matrix = std::make_unique<Matrix>(14);
            for (int i = 0; i < 14; ++i) {
                (*matrix)[i] = i + 1; 
            }

            auto generator = std::make_unique<RandomGenerator>(1, 10);
            Task3Exercise exercise(std::move(matrix), std::move(generator));

            exercise.Task3();

            const Matrix& result = exercise.get_matrix();

            
            Assert::AreEqual(0, result[0]);
            Assert::AreEqual(1, result[1]);

      
            Assert::AreEqual(-9, result[2]);   
            Assert::AreEqual(-16, result[3]);  
            Assert::AreEqual(-25, result[4]);  

           
            Assert::AreEqual(12, result[12]); 
            Assert::AreEqual(13, result[13]); 
        }

        TEST_METHOD(TestTask3_SmallArray)
        {
            auto matrix = std::make_unique<Matrix>(3);
            (*matrix)[0] = 1;
            (*matrix)[1] = 2;
            (*matrix)[2] = 3;

            auto generator = std::make_unique<RandomGenerator>(1, 10);
            Task3Exercise exercise(std::move(matrix), std::move(generator));

            exercise.Task3();

            const Matrix& result = exercise.get_matrix();

            Assert::AreEqual(0, result[0]); 
            Assert::AreEqual(1, result[1]); 
            Assert::AreEqual(-9, result[2]);
        }
    };

    TEST_CLASS(IntegrationTests)
    {
    public:

        TEST_METHOD(TestExerciseGetMatrix)
        {
            auto matrix = std::make_unique<Matrix>(3);
            (*matrix)[0] = 10;
            (*matrix)[1] = 20;
            (*matrix)[2] = 30;

            auto generator = std::make_unique<RandomGenerator>(1, 10);
            Task1Exercise exercise(std::move(matrix), std::move(generator));

            const Matrix& result = exercise.get_matrix();
            Assert::AreEqual(size_t(3), result.size());
            Assert::AreEqual(10, result[0]);
            Assert::AreEqual(20, result[1]);
            Assert::AreEqual(30, result[2]);
        }
    };
}