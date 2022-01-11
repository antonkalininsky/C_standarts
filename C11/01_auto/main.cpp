/* информация:
 * auto - ключевое слово, которое позволяет не указывать тип
 * переменной явно
 *
 * позволяет сократить код и облегчить жизнь если речь идет об итераторах
 *
 * создает простейший возможный тип для объяснения происходящего,
 * поэтому в примере 1 D это не string а const char*
 *
 */

#include <QCoreApplication>
#include <iostream>
#include <type_traits>
#include <vector>

class superClass {
public:
    int A;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // пример 1: просто переменные
    std::cout << "example 1: just variables\n";
    auto A = 10; //int
    auto B = 1.1; //double
    auto C = new superClass(); // superClass*
    delete C;
    auto D = "hello auto"; // const char*

    std::cout << "A is int: " << std::is_same<int, decltype(A)>::value << "\n";
    std::cout << "B is double: " << std::is_same<double, decltype(B)>::value << "\n";
    std::cout << "C is superClass*: " << std::is_same<superClass*, decltype(C)>::value << "\n";
    std::cout << "D is const char*: " << std::is_same<const char*, decltype(D)>::value << "\n";


    // пример 2: итераторы
    std::cout << "\n";
    std::cout << "example 2: iterators\n";
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    std::cout << "vector v with 7 elements created!\nlets see its content: ";
    for(auto it = v.cbegin(); it!=v.cend(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "and in reverse: ";
    for(auto it = v.crbegin(); it!=v.crend(); it++) {
        std::cout << *it << " ";
    }
    // для сравнения
    std::vector<int>::const_reverse_iterator it;

    return a.exec();
}

