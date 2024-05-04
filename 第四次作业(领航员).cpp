#include <iostream>
#include <vector>
#include <string>
#include <cassert>

#include "arithmetic_expression.h" // 假设这是您要测试的代码文件

using namespace std;

// 测试函数 generate_random_number
void test_generate_random_number() {
    for (int i = 0; i < 100; ++i) {
        int max_number = rand() % 100;
        int result = generate_random_number(max_number);
        assert(result >= 0 && result <= max_number);
    }
}

// 测试函数 generate_operator
void test_generate_operator() {
    vector<char> operators = {'+', '-', '*', '/'};
    for (int i = 0; i < 100; ++i) {
        char result = generate_operator();
        assert(find(operators.begin(), operators.end(), result) != operators.end());
    }
}

// 测试函数 generate_expression
void test_generate_expression(int max_number, char operato, bool has_decimal) {
    int num1 = generate_random_number(max_number);
    int num2 = generate_random_number(max_number);
    if (operato == '/' && num2 == 0) {
        num2 = 1; // avoid division by zero
    }
    string expected_output;
    if (has_decimal) {
        expected_output = to_string(num1) + " " + operato + " " + to_string(num2) + " = " + to_string((float)num1 / num2);
    } else {
        expected_output = to_string(num1) + " " + operato + " " + to_string(num2) + " = " + to_string(num1 / num2);
    }
    string actual_output = generate_expression(max_number, operato, has_decimal);
    assert(actual_output == expected_output);
}

int main() {
    test_generate_random_number();
    test_generate_operator();
    test_generate_expression(10, '+', false);
    test_generate_expression(100, '-', true);
    test_generate_expression(50, '*', false);
    test_generate_expression(20, '/', true);
    cout << "All tests passed!" << endl;
    return 0;
}
