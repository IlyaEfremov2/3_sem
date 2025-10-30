#include <iostream>
#include <memory>
#include <locale>
#include <limits>
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

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
    setlocale(LC_ALL, "Russian");
    try
    {
        cout << "1 - Случайные числа" << endl;
        cout << "2 - Ввод с клавиатуры" << endl;

        int choice;
        cin >> choice;
        clearInputBuffer();

        unique_ptr<Matrix> matrix;
        size_t size;

        if (choice == 1) {
            cout << "Введите размер матрицы: ";
            cin >> size;
            clearInputBuffer();

            if (size == 0) {
                throw invalid_argument("Размер матрицы не может быть 0");
            }

            matrix = make_unique<Matrix>(size);

            int min_val, max_val;
            cout << "Минимальное значение: ";
            cin >> min_val;
            cout << "Максимальное значение: ";
            cin >> max_val;
            clearInputBuffer();

            auto random_gen = make_unique<RandomGenerator>(min_val, max_val);
            matrix->fill(move(random_gen));
            cout << "Матрица заполнена случайными числами от " << min_val << " до " << max_val << endl;
        }
        else if (choice == 2) {
            cout << "Размер матрицы: ";
            cin >> size;
            clearInputBuffer();

            if (size == 0) {
                throw invalid_argument("Размер матрицы не может быть 0");
            }

            matrix = make_unique<Matrix>(size);
            auto input_gen = make_unique<IStreamGenerator>();
            cout << "Введите " << size << " элементов матрицы: ";
            matrix->fill(move(input_gen));
            clearInputBuffer();
            cout << "Матрица заполнена вручную" << endl;
        }

        cout << "Исходная матрица: " << matrix->to_string() << endl;

        auto exercise1 = make_unique<Task1Exercise>(
            make_unique<Matrix>(*matrix),
            make_unique<RandomGenerator>(0, 0)
        );
        exercise1->execute();
        cout << "После задания 1: " << exercise1->get_matrix().to_string() << endl;

        auto exercise2 = make_unique<Task2Exercise>(
            make_unique<Matrix>(*matrix),
            make_unique<RandomGenerator>(0, 0)
        );
        exercise2->execute();
        cout << "После задания 2: " << exercise2->get_matrix().to_string() << endl;

        auto exercise3 = make_unique<Task3Exercise>(
            make_unique<Matrix>(*matrix),
            make_unique<RandomGenerator>(0, 0)
        );
        exercise3->execute();
        cout << "После задания 3: " << exercise3->get_matrix().to_string() << endl;

    }
    catch (const exception& e)
    {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}