#include <iostream>
#include <cstdlib>
#include <clocale>
#include <stack>
#include <string>
#include <cctype>

using namespace std;
int main()
{
  string infix;
  getline(std::cin, infix);
  cout << PostfixOperations(Transform(infix));
  return EXIT_SUCCESS;
}

int PostfixOperations(const std::string& str) {
    std::stack<std::string> buffer;
    std::stack<int> result;
    std::string temp;
    char operations[] = {'+', '*', '-', '/', '='};

    for (int i = str.length() - 1; i >= 0; --i) {
        if (isdigit(str[i])) {
            temp = str[i] + temp;
            if (i == 0) buffer.push(temp);
        } else if (str[i] == ' ' && !temp.empty()) {
            buffer.push(temp);
            temp = "";
        } else {
            for (char j : operations) {
                if (str[i] == j) {
                    buffer.push(std::string(1, str[i]));
                    break;
                }
            }
        }
    }

    while (!buffer.empty()) {
        temp = buffer.top();
        buffer.pop();
        int number;

        if (std::stoi(temp, nullptr) || temp == "0") { // Проверяем, является ли строка числом
            result.push(std::stoi(temp));
        } else if (temp == "=") {
            return result.top();
        } else {
            int numberSecond = result.top();
            result.pop();
            int numberFirst = result.top();
            result.pop();

            if (temp == "+") result.push(numberFirst + numberSecond);
            else if (temp == "-") result.push(numberFirst - numberSecond);
            else if (temp == "*") result.push(numberFirst * numberSecond);
            else if (temp == "/") result.push(numberFirst / numberSecond);
        }
    }
    return 0; // Возвращаем 0, если стек пуст
}
---------------------------------------------------------------------------
// Функция для определения приоритета оператора
int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string Transform(string infix) {
    string postfix;
    stack<char> operators;
    cout << "Введите выражение в инфиксной нотации: ";
    getline(std::cin, infix);

    for (char c : infix) {
        if (isalnum(c)) {  // Если символ - операнд (число или буква)
            postfix += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();  // Удаляем открывающую скобку
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!operators.empty() && priority(operators.top()) >= priority(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}
