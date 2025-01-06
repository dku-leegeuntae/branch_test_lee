#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <cmath> // 수학 함수들 (sqrt, pow, sin, cos, tan, log, etc.)
#include <stdexcept> // 예외 처리 (예: 나누기 0)

class Calculator {
public:
    // 기본 연산 함수들
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);

    // 제곱근과 제곱 함수
    double sqrt(double a);
    double power(double base, double exponent);

    // 삼각 함수 (라디안 단위)
    double sin(double angle);
    double cos(double angle);
    double tan(double angle);

    // 로그 함수
    double logBase10(double a);
    double logBaseE(double a);

    // 예외 처리: 0으로 나누기를 방지
    class DivisionByZeroException : public std::exception {
    public:     // 접근 제한자 변경 : public
        const char* what() const noexcept override {
            return "Error: Division by zero is not allowed!";
        }
    };
};

#endif // CALCULATOR_H
