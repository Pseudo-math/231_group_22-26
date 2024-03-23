#include <iostream>
#include <vector>
#include <algorithm>

void find_index(std::vector<double> & vec, double x, int & i, int & j) {
    auto lower = std::lower_bound(vec.begin(), vec.end(), x);
    auto elem = std::find(vec.begin(), vec.end(), x);
    if (elem != vec.end()) {
        i = distance(vec.begin(), elem);
        j = i;
    }
    else if (lower == vec.end()) {
        i = vec.size() - 1;
        j = vec.size();
    } else if (lower == vec.begin()) {
        i = -1;
        j = 0;
    } else {
        i = std::distance(vec.begin(), lower - 1);
        j = std::distance(vec.begin(), lower);
    }
}

int main() {
    std::vector<double> vec = {1.0, 2.0, 3.0, 5.0, 7.0, 9.0};
    double x = 4.0;
    int i, j;

    find_index(vec, x, i, j);

    std::cout << i << " " << j << std::endl;

    return 0;
}
