#include <iostream>
#include "Calculator.h"

int main() {
    Calculator calc;

    double a = 10.0;
    double b = 5.0;

    try {
        // 기본 연산
        std::cout << "a + b = " << calc.add(a, b) << std::endl;
        std::cout << "a - b = " << calc.subtract(a, b) << std::endl;
        std::cout << "a * b = " << calc.multiply(a, b) << std::endl;
        std::cout << "a / b = " << calc.divide(a, b) << std::endl;

        // 제곱근과 제곱
        std::cout << "sqrt(a) = " << calc.sqrt(a) << std::endl;
        std::cout << "a^b = " << calc.power(a, b) << std::endl;

        // 삼각 함수 (라디안 단위)
        std::cout << "sin(a) = " << calc.sin(a) << std::endl;
        std::cout << "cos(a) = " << calc.cos(a) << std::endl;
        std::cout << "tan(a) = " << calc.tan(a) << std::endl;

        // 로그 함수
        std::cout << "log10(a) = " << calc.logBase10(a) << std::endl;
        std::cout << "ln(a) = " << calc.logBaseE(a) << std::endl;

    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
