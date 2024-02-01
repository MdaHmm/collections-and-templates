// ��� ����������� ���������� ������ � ���� ����������, �������� ���� ���, 
// ������� �������� ��������, �������� � ������������ �����.
// � ���� ���������� ����������� ������ �� ��������, ������� ����� 
// ������ �����������. �������� ������� � ��������������� ������ ������� 
// �� �������� ���������.

#pragma once

#ifndef MATH_OPERATOR_HPP
#define MATH_OPERATOR_HPP

#include <iostream>

template<typename Type>
class MathOperator {
public:
    //����������� �� ���������
    MathOperator() :operand1_(Type()), operand2_(Type()) {}
    //� �������� ����� ������������ Type() ��� ������������� � ����� ��������� 
    //�������� �����

    // ����������� � ����������
    MathOperator(Type left, Type rigth) :operand1_(left), operand2_(rigth) {}

    // ������� ��������� ��������� ���������� ���� ������
    // ��� ��������� �������� ������� ���������� � ���� ���� �� ���������� ����
    void SetLeft(Type num) {
        operand1_ = num;
    }
    void SetRight(Type num) {
        operand2_ = num;
    }

    //������� ���������� ��������� ��� ����� �� ���� ���������� ��� �������� �����
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

    // ����������� � ����������
    MathOperator(bool left, bool rigth) :operand1_(left), operand2_(rigth) {}

    // ������� ��������� ��������� ���������� ���� ������
    // ��� ��������� �������� ������� ���������� � ���� ���� �� ���������� ����
    void SetLeft(bool num) {
        operand1_ = num;
    }
    void SetRight(bool num) {
        operand2_ = num;
    }

    //������� ���������� ��������� ��� ����� �� ���� ���������� ��� �������� �����
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


// ��������� �������� ��������� ������

// ������� 1
// ��������� ���������� �������������

void PrintSumm(const MathOperator<int>& obj);

// ������� 2
// ��������� ����������� ����

template<typename T>
void PrintMultiply(const MathOperator<T>& obj) {
    std::cout << obj.GetLeft() << '*' << obj.GetRight() <<
        '=' << obj.Multiply() << '\n';
}

//������� �������� ���������� � ������������� �������
template<>
void PrintMultiply<bool>(const MathOperator<bool>& obj) {
    // ������� 1 ���������: ������ ����������
    // throw -1; ���� ��� �� ������ �� �������� � ����������� ����������
    // ��������� ����� ������� � ������� � ��������������� ������ �������

    // ������� 2 ���������: �������� � ������ ������������ ������� ������
    std::cout << obj.GetLeft() << '*' << obj.GetRight() <<
        " not allowed operations";
}




#endif //MATH_OOPERATOR_HPP