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
