#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <cmath> // ���� �Լ��� (sqrt, pow, sin, cos, tan, log, etc.)
#include <stdexcept> // ���� ó�� (��: ������ 0)

class Calculator {
public:
    // �⺻ ���� �Լ���
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);

    // �����ٰ� ���� �Լ�
    double sqrt(double a);
    double power(double base, double exponent);

    // �ﰢ �Լ� (���� ����)
    double sin(double angle);
    double cos(double angle);
    double tan(double angle);

    // �α� �Լ�
    double logBase10(double a);
    double logBaseE(double a);

    // ���� ó��: 0���� �����⸦ ����
    class DivisionByZeroException : public std::exception {
    public:     // ���� ������ ���� : public
        const char* what() const noexcept override {
            return "Error: Division by zero is not allowed!";
        }
    };
};

#endif // CALCULATOR_H
