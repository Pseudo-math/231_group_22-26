#include <iostream>
#include <vector>

std::vector<int> repeat(std::vector<int> & v, int n) {
    std::vector<int> result;
    for (int i = 0; i < n; ++i) {
        result.insert(result.end(), v.begin(), v.end());
    }
    return result;
}

int main() {
    std::vector<int> old = {1, 2, 3};
    int сount = 3;

    std::vector<int> repeated = repeat(old, сount);

    for (int x : repeated) {
        std::cout << x << " ";
    }

    return 0;
}
