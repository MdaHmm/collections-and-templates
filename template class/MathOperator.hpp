// При организации шаблонного класса в виде библиотеки, треуется весь код, 
// который является шаблоном, оставить в заголовочном файле.
// В файл реализации переносятся только те элементы, которые имеют 
// полное определение. Например функции и вспомогательные классы которые 
// не являются шаблонами.

#pragma once

#ifndef MATH_OPERATOR_HPP
#define MATH_OPERATOR_HPP

#include <iostream>

template<typename Type>
class MathOperator {
public:
    //конструктор по умолчанию
    MathOperator() :operand1_(Type()), operand2_(Type()) {}
    //в создании полей используется Type() для совместимости с любым возможным 
    //харнимым типом

    // конструктор с параметром
    MathOperator(Type left, Type rigth) :operand1_(left), operand2_(rigth) {}

    // сеттеры принимают аргументы шаблонного типа данных
    // это позволяет коректно занести информацию в поля того же шаблонного типа
    void SetLeft(Type num) {
        operand1_ = num;
    }
    void SetRight(Type num) {
        operand2_ = num;
    }

    //геттеры возвразают шаблонный тип чтобы не было конфликтов при возврате полей
    Type GetLeft()const {
        return operand1_;
    }
    Type GetRight()const {
        return operand2_;
    }

    Type Summ() const {
        return operand1_ + operand2_;
    }
    Type Multiply() const {
        return operand1_ * operand2_;
    }
private:
    Type operand1_;
    Type operand2_;
};

template<>
class MathOperator<bool> {
public:
    MathOperator() :operand1_(false), operand2_(false) {}

    // конструктор с параметром
    MathOperator(bool left, bool rigth) :operand1_(left), operand2_(rigth) {}

    // сеттеры принимают аргументы шаблонного типа данных
    // это позволяет коректно занести информацию в поля того же шаблонного типа
    void SetLeft(bool num) {
        operand1_ = num;
    }
    void SetRight(bool num) {
        operand2_ = num;
    }

    //геттеры возвразают шаблонный тип чтобы не было конфликтов при возврате полей
    bool GetLeft()const {
        return operand1_;
    }
    bool GetRight()const {
        return operand2_;
    }

    bool Summ() const {
        return operand1_ || operand2_;
    }

private:
    bool operand1_;
    bool operand2_;
};


// обработка объектов шабонного класса

// вариант 1
// обработка конкретной специализации

void PrintSumm(const MathOperator<int>& obj);

// вариант 2
// обработка обобщённого вида

template<typename T>
void PrintMultiply(const MathOperator<T>& obj) {
    std::cout << obj.GetLeft() << '*' << obj.GetRight() <<
        '=' << obj.Multiply() << '\n';
}

//решение проблемы обработкой в специализации шаблона
template<>
void PrintMultiply<bool>(const MathOperator<bool>& obj) {
    // вариант 1 обработки: кидаем исключение
    // throw -1; если так не делать то проблема с некоректным поведением
    // программы может вылезти в будущем в непредсказуемый момент времени

    // вариант 2 обработки: работаем с учётом особенностей входных данных
    std::cout << obj.GetLeft() << '*' << obj.GetRight() <<
        " not allowed operations";
}




#endif //MATH_OOPERATOR_HPP