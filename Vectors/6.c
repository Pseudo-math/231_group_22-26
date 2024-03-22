#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int>::iterator second_occurrence(std::vector<int> & vec, int value) {
    std::vector<int>::iterator first = std::find(vec.begin(), vec.end(), value);
    if (first == vec.end()) {
        return vec.end();
    }

    std::vector<int>::iterator second = std::find(first + 1, vec.end(), value);
    if (second == vec.end()) {
        return vec.end();
    }

    return second;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 2, 5, 6, 2, 7};
    int value = 2;

    std::vector<int>::iterator result = second_occurrence(numbers, value);

    if (result != numbers.end()) {
        std::cout << std::distance(numbers.begin(), result) << std::endl;
    } else {
        std::cout << std::endl;
    }

    return 0;
}
