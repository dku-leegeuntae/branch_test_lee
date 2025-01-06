#include <iostream>
#include <limits>
#include "Calculator.h"

void printMenu() {
    std::cout << "Select an operation:\n";
    std::cout << "1. Add\n";
    std::cout << "2. Subtract\n";
    std::cout << "3. Multiply\n";
    std::cout << "4. Divide\n";
    std::cout << "5. Square Root\n";
    std::cout << "6. Power (x^y)\n";
    std::cout << "7. Sin (radians)\n";
    std::cout << "8. Cos (radians)\n";
    std::cout << "9. Tan (radians)\n";
    std::cout << "10. Log (Base 10)\n";
    std::cout << "11. Log (Base e)\n";
    std::cout << "12. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Calculator calc;
    int choice;
    double a, b;

    while (true) {
        printMenu();
        std::cin >> choice;

        // 오류 처리: 입력값이 숫자가 아닐 경우
        if (std::cin.fail()) {
            std::cin.clear();  // 입력 스트림을 초기화
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // 잘못된 입력을 무시
            std::cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:  // 더하기
            std::cout << "Enter two numbers: ";
            std::cin >> a >> b;
            std::cout << "Result: " << calc.add(a, b) << std::endl;
            break;

        case 2:  // 빼기
            std::cout << "Enter two numbers: ";
            std::cin >> a >> b;
            std::cout << "Result: " << calc.subtract(a, b) << std::endl;
            break;

        case 3:  // 곱하기
            std::cout << "Enter two numbers: ";
            std::cin >> a >> b;
            std::cout << "Result: " << calc.multiply(a, b) << std::endl;
            break;

        case 4:  // 나누기
            std::cout << "Enter two numbers: ";
            std::cin >> a >> b;
            try {
                std::cout << "Result: " << calc.divide(a, b) << std::endl;
            }
            catch (const Calculator::DivisionByZeroException& e) {
                std::cout << e.what() << std::endl;
            }
            break;

        case 5:  // 제곱근
            std::cout << "Enter a number: ";
            std::cin >> a;
            try {
                std::cout << "Result: " << calc.sqrt(a) << std::endl;
            }
            catch (const std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
            }
            break;

        case 6:  // 제곱
            std::cout << "Enter base and exponent: ";
            std::cin >> a >> b;
            std::cout << "Result: " << calc.power(a, b) << std::endl;
            break;

        case 7:  // 사인
            std::cout << "Enter angle in radians: ";
            std::cin >> a;
            std::cout << "Result: " << calc.sin(a) << std::endl;
            break;

        case 8:  // 코사인
            std::cout << "Enter angle in radians: ";
            std::cin >> a;
            std::cout << "Result: " << calc.cos(a) << std::endl;
            break;

        case 9:  // 탄젠트
            std::cout << "Enter angle in radians: ";
            std::cin >> a;
            std::cout << "Result: " << calc.tan(a) << std::endl;
            break;

        case 10:  // 로그 (Base 10)
            std::cout << "Enter a number: ";
            std::cin >> a;
            try {
                std::cout << "Result: " << calc.logBase10(a) << std::endl;
            }
            catch (const std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
            }
            break;

        case 11:  // 로그 (Base e)
            std::cout << "Enter a number: ";
            std::cin >> a;
            try {
                std::cout << "Result: " << calc.logBaseE(a) << std::endl;
            }
            catch (const std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
            }
            break;

        case 12:  // 종료
            std::cout << "Exiting the calculator. Goodbye!" << std::endl;
            return 0;

        default:
            std::cout << "Invalid choice! Please try again.\n";
        }

        std::cout << std::endl;  // 결과 출력 후 간격을 둠
    }

    return 0;
}
