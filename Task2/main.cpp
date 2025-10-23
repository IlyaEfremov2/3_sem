#include <iostream>
#include <memory>
#include <locale>
#include "../desicion2/Matrix.h"
#include "../desicion2/Generator.h"
#include "../desicion2/Exercise.h"
#include "../desicion2/RandomGenerator.h"
#include "../desicion2/IStreamGenerator.h"
#include "../desicion2/Task1Exercise.h"
#include "../desicion2/Task2Exercise.h"
#include "../desicion2/Task3Exercise.h"

using namespace miit::algebra;
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    try
    {
        cout << "Демонстрация работы с матрицей" << endl;

        auto matrix = make_unique<Matrix>(6);
        auto random_gen = make_unique<RandomGenerator>(-10, 10);
        matrix->fill(move(random_gen));

        cout << "Исходная матрица: " << matrix->to_string() << endl;

        auto exercise1 = make_unique<Task1Exercise>(
            make_unique<Matrix>(*matrix),
            make_unique<RandomGenerator>(0, 0)
        );
        exercise1->Task1();
        cout << "После задания 1: " << exercise1->get_matrix().to_string() << endl;

        auto exercise2 = make_unique<Task2Exercise>(
            make_unique<Matrix>(*matrix),
            make_unique<RandomGenerator>(0, 0)
        );
        auto result2 = exercise2->Task2();
        cout << "После задания 2: " << result2->to_string() << endl;

        auto exercise3 = make_unique<Task3Exercise>(
            make_unique<Matrix>(*matrix),
            make_unique<RandomGenerator>(0, 0)
        );
        exercise3->Task3();
        cout << "После задания 3: " << exercise3->get_matrix().to_string() << endl;
    }
    catch (const exception& e)
    {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}