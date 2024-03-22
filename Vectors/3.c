#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int arr[5] = {0};

    std::copy(vec.begin(), vec.end(), arr);

    for (int x : arr) {
        std::cout << x << " ";
    }

    return 0;
}
