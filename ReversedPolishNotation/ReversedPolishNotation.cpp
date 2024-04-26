#include <iostream>
#include <cstdlib>
#include <clocale>
#include <stack>
using namespace std;
int main()
{
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

      
