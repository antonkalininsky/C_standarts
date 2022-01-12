/* информация:
 * range-based loops - циклы итерации по набору
 *
 * упрощенный перебор контейнеров
 */

#include <QCoreApplication>
#include <vector>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // пример 1: перебор вектора без изменений
    std::cout << "example 1: looping through vector\n";
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    std::cout << "vector v with 7 elements created!\nlets see its content: ";
    for (const auto it: v) {
        std::cout << it << " ";
    }
    std::cout << "\n\n";

    // пример 2: перебор вектора с изменениями
    std::cout << "example 2: looping and changing through vector\n";
    std::cout << "content of vector v: ";
    for (const auto it: v) {
        std::cout << it << " ";
    }
    for (auto &it: v) {
        it *= 2;
    }
    std::cout << "\n";
    std::cout << "after changes: ";
    for (const auto it: v) {
        std::cout << it << " ";
    }



    return a.exec();
}

