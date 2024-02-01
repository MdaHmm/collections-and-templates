#include <iostream>

#include "MathOperator.hpp"

int main()
{
    std::cout << "Hello World!\n";
    const MathOperator<float> f(1.,2.);
    std::cout << f.Summ() << '\n';
    //f.SetLeft(6); для константного контекста невозможно 
    //              вызвать неконстантный метод
    std::cout << f.GetLeft() << '+' << f.GetRight() <<
        '=' << f.Summ() << '\n';
    // остальное взаимодействие аналагично любым другим объектам класса


    MathOperator<float> f2(1.5, 2.9);
    std::cout << f2.Summ() << '\n';

    f2.SetRight(f2.GetRight() + 1.6);
    std::cout << f2.GetLeft() <<'+'<< f2.GetRight() << 
        '=' << f2.Summ() << '\n';
    //MathOperator<bool> b;
    
    std::cout << 4 << '*' << 9 <<
        '=' <<  MathOperator<int>(4,9).Multiply() << '\n';
    // при работе с шаблонными классами нет запретов на использование анонимных
    // объектов
    // при создании анонимного объекта от шаблонного класса
    // так же указывается его специализация

    PrintSumm(MathOperator<int>(4, 9));

    const MathOperator<int>  int_m(1, 54);
    PrintSumm(int_m);
    //PrintSumm(f2); невозможно так как в функции упомянута конкретная реализация

    PrintMultiply(f);
    PrintMultiply(int_m);
    PrintMultiply(MathOperator<bool>(true, false));
}