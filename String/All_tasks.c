#include <iostream>
#include <string>

int IP_check(std::string IP_or_not) {
    std::string temp;
    int i = 0, j = 0, count_pieces = 0;
    for (char x : IP_or_not) {
        if ((j - i >= 4)  or count_pieces >= 4) return 0;
        if (x == '.') {
            temp = IP_or_not.substr(i, j - i);
            if ((0 <= std::stoi(temp)) and (std::stoi(temp) <= 255)) {
                i = j + 1;
            }
            else return 0;
            ++count_pieces;
        }
        else if (!(isdigit(x))) return 0;
        ++j;
    }
    return 1;
}

int main() {
    std::string s = "0.233.34.1";
    std::cout << IP_check(s);
    return 0;
}
--------------------------------------------------------------------
#include <iostream>
#include <string>

std::string find_substring(std::string str1, std::string str2) {
    std::string result = str1;
    int len = str2.length();
    int i = 0;
    i = result.find(str2,i);
    while (i != std::string::npos) {
        result.insert(i, "(");
        result.insert(i + len + 1, ")");
        i = result.find(str2, i + len + 3);
    }
    return result;
}

int main() {
    std::string str1 = "3000300233.300.1", str2 = "300";
    std::cout << find_substring(str1, str2);
    return 0;
}
