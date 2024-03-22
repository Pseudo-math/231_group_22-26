#include <iostream>
#include <vector>

void del(std::vector<int> & vec) {
    std::vector<int>::iterator i = vec.begin();
    while (i  != vec.end()) {
        i = vec.erase(i);
        if (i != vec.end()) ++i;
    }
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    del(numbers);

    for (int x : numbers) {
        std::cout << x << " ";
    }

    return 0;
}
    
