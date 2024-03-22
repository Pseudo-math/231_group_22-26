#include <iostream>
#include <vector>

std::vector<int> concat(std::vector<int> & vec1, std::vector<int> & vec2) {
    std::vector<int> result = vec1;
    result.insert(result.end(), vec2.begin(), vec2.end());
    return result;
}

int main() {
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};

    std::vector<int> concatenated = concat(vec1, vec2);

    for (int x : concatenated) {
        std::cout << x << " ";
    }

    return 0;
}
