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

        // ���� ó��: �Է°��� ���ڰ� �ƴ� ���
        if (std::cin.fail()) {
            std::cin.clear();  // �Է� ��Ʈ���� �ʱ�ȭ
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // �߸��� �Է��� ����
            std::cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:  // ���ϱ�
            std::cout << "Enter two numbers: ";
            std::cin >> a >> b;
            std::cout << "Result: " << calc.add(a, b) << std::endl;
            break;

        case 2:  // ����
            std::cout << "Enter two numbers: ";
            std::cin >> a >> b;
            std::cout << "Result: " << calc.subtract(a, b) << std::endl;
            break;

        case 3:  // ���ϱ�
            std::cout << "Enter two numbers: ";
            std::cin >> a >> b;
            std::cout << "Result: " << calc.multiply(a, b) << std::endl;
            break;

        case 4:  // ������
            std::cout << "Enter two numbers: ";
            std::cin >> a >> b;
            try {
                std::cout << "Result: " << calc.divide(a, b) << std::endl;
            }
            catch (const Calculator::DivisionByZeroException& e) {
                std::cout << e.what() << std::endl;
            }
            break;

        case 5:  // ������
            std::cout << "Enter a number: ";
            std::cin >> a;
            try {
                std::cout << "Result: " << calc.sqrt(a) << std::endl;
            }
            catch (const std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
            }
            break;

        case 6:  // ����
            std::cout << "Enter base and exponent: ";
            std::cin >> a >> b;
            std::cout << "Result: " << calc.power(a, b) << std::endl;
            break;

        case 7:  // ����
            std::cout << "Enter angle in radians: ";
            std::cin >> a;
            std::cout << "Result: " << calc.sin(a) << std::endl;
            break;

        case 8:  // �ڻ���
            std::cout << "Enter angle in radians: ";
            std::cin >> a;
            std::cout << "Result: " << calc.cos(a) << std::endl;
            break;

        case 9:  // ź��Ʈ
            std::cout << "Enter angle in radians: ";
            std::cin >> a;
            std::cout << "Result: " << calc.tan(a) << std::endl;
            break;

        case 10:  // �α� (Base 10)
            std::cout << "Enter a number: ";
            std::cin >> a;
            try {
                std::cout << "Result: " << calc.logBase10(a) << std::endl;
            }
            catch (const std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
            }
            break;

        case 11:  // �α� (Base e)
            std::cout << "Enter a number: ";
            std::cin >> a;
            try {
                std::cout << "Result: " << calc.logBaseE(a) << std::endl;
            }
            catch (const std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
            }
            break;

        case 12:  // ����
            std::cout << "Exiting the calculator. Goodbye!" << std::endl;
            return 0;

        default:
            std::cout << "Invalid choice! Please try again.\n";
        }

        std::cout << std::endl;  // ��� ��� �� ������ ��
    }

    return 0;
}
