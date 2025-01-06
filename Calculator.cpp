#include "Calculator.h"

// 기본 연산 함수들
double Calculator::add(double a, double b) {
    return a + b;
}

double Calculator::subtract(double a, double b) {
    return a - b;
}

double Calculator::multiply(double a, double b) {
    return a * b;
}

double Calculator::divide(double a, double b) {
    if (b == 0) {
        throw DivisionByZeroException();
    }
    return a / b;
}

// 제곱근 함수
double Calculator::sqrt(double a) {
    if (a < 0) {
        throw std::invalid_argument("Error: Negative input for sqrt!");
    }
    return std::sqrt(a);
}

// 제곱 함수
double Calculator::power(double base, double exponent) {
    return std::pow(base, exponent);
}

// 삼각 함수 (라디안 단위)
double Calculator::sin(double angle) {
    return std::sin(angle);
}

double Calculator::cos(double angle) {
    return std::cos(angle);
}

double Calculator::tan(double angle) {
    return std::tan(angle);
}

// 로그 함수
double Calculator::logBase10(double a) {
    if (a <= 0) {
        throw std::invalid_argument("Error: Logarithm input must be greater than zero!");
    }
    return std::log10(a);
}

double Calculator::logBaseE(double a) {
    if (a <= 0) {
        throw std::invalid_argument("Error: Logarithm input must be greater than zero!");
    }
    return std::log(a);
}
