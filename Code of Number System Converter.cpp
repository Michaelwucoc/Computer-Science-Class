#include <iostream>
#include <string>
#include <cmath>

// 函数声明，将数字从一个进制转换为另一个进制
std::string convertBase(const std::string& num, int fromBase, int toBase);

int main() {
    std::string inputNum;
    int fromBase, toBase;

    // 提示用户输入要转换的数字和进制
    std::cout << "请输入要转换的数字: ";
    std::cin >> inputNum;

    std::cout << "请输入原始进制: ";
    std::cin >> fromBase;

    std::cout << "请输入目标进制: ";
    std::cin >> toBase;

    // 调用函数进行进制转换并输出结果
    std::string result = convertBase(inputNum, fromBase, toBase);
    std::cout << "转换结果: " << result << std::endl;

    return 0;
}

// 函数实现，将数字从一个进制转换为另一个进制
std::string convertBase(const std::string& num, int fromBase, int toBase) {
    // 首先将输入数字从原始进制转换为十进制
    int decimalValue = 0;
    int power = 0;

    for (int i = num.length() - 1; i >= 0; --i) {
        char digit = num[i];
        int digitValue;

        if (isdigit(digit)) {
            digitValue = digit - '0';
        } else if (isalpha(digit)) {
            digitValue = std::toupper(digit) - 'A' + 10;
        } else {
            std::cerr << "无效的输入数字。" << std::endl;
            exit(1);
        }

        if (digitValue >= fromBase) {
            std::cerr << "输入数字不符合原始进制。" << std::endl;
            exit(1);
        }

        decimalValue += digitValue * std::pow(fromBase, power);
        ++power;
    }

    // 然后将十进制值从十进制转换为目标进制
    std::string result = "";
    while (decimalValue > 0) {
        int remainder = decimalValue % toBase;
        char digitChar;

        if (remainder < 10) {
            digitChar = '0' + remainder;
        } else {
            digitChar = 'A' + remainder - 10;
        }

        result = digitChar + result;
        decimalValue /= toBase;
    }

    return result;
}
