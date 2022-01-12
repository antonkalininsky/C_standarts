/* информация:
 * virtual - ключевое слово при объявлении методов класса, необходимо для переопеределения дочерних методов
 *
 * override - идентификатор для указания на то что метод является переропределением виртуального метода в базовом классе
 *
 * final - идентификатор для указания на то что метод не должен переопределяться при наследовании
 *
 */

#include <QCoreApplication>
#include <iostream>

// базовый класс
class A {
public:
    virtual void foo() {
        std::cout << "A::foo()\n";
    }
};

// дочерний класс с простым переопределением функции
class B1 : public A {
public:
    virtual void foo() {
        std::cout << "B1::foo()\n";
    }
};

// дочерний класс с ошибочным простым "переопределением" функции (создание скрытых методов)
class B2 : public A {
public:
    virtual void foo(int A) {
        std::cout << "B2::foo(int)\n";
    }
};

// дочерний класс с переопределением функции с использованием override (не позволит допустить ошибку как B2)
class C1 : public A {
public:
    virtual void foo() override {
        std::cout << "C1::foo()\n";
    }
};

// ожидаемая ошибка компиляции
/*
class C2 : public A {
public:
    virtual foo(int A) override {
        std::cout << "С2::foo()\n";
    }
};
*/

// дочерний класс с переопределением функции с использованием final (дальнейшее переопеределение невозможно)
class D : public A {
public:
    virtual void foo() override final {
        std::cout << "D::foo()\n";
    }
};

// попытка переопределения в дочернем классе от final
// ожидаемая ошибка компиляции
/*
class E : public D {
public:
    virtual void foo() {
        std::cout << "E::foo()\n";
    }
};
*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // пример 1: простое переопределение virtual
    std::cout << "example 1: redefinition using virtual\n";
    std::cout << "class A created! calling its method: ";
    A aa;
    aa.foo();
    std::cout << "class B1 inherited from class A! calling method B1: ";
    B1 bb1;
    bb1.foo();
    std::cout << "\n";

    // пример 2: ошибочное переопределение (создание скрытых методов) virtual
    std::cout << "example 2: redefinition using virtual with mistake (leaving hide base methods)\n";
    std::cout << "class B2 inherited from class A in a bad way! calling method foo(int) B2: ";
    B2 bb2;
    bb2.foo(10);
    std::cout << "foo() still exist";
    std::cout << "\n\n";

    // пример 3: использование override при переопределении
    std::cout << "example 3: redefinition using override\n";
    std::cout << "class C1 inherited from class A using override! calling method foo() C1: ";
    C1 cc1;
    cc1.foo();
    std::cout << "\n";

    // пример 4: использование final при переопределении
    std::cout << "example 4: redefinition using final\n";
    std::cout << "class D inherited from class A using final! calling method foo() D: ";
    D dd;
    dd.foo();
    std::cout << "\n";

    return a.exec();
}

