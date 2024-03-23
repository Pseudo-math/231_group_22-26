#include <iostream>
#include <vector>
#include <algorithm>

int last_ossure(std::vector <int> & vec, int value) {
    auto iter = std::find(vec.rbegin(), vec.rend(), value);
    return distance(vec.begin(), iter.base() - 1);
}

int main() {
    std::vector<int> numbers = {3, 2, 5, 9, 4, 5, 7, 1, 5, 8};
    int value = 2;
    
    std::cout << last_ossure(numbers, value);
    
    return 0;
}
