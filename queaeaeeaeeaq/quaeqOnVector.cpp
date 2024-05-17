#include <iostream>
#include <vector>

class Queue {
private:
    std::vector<int> arr;
    int frontIndex;

public:
    Queue(int size = 1000) : arr(size), frontIndex(0) {}

    int pop() {
        if (isEmpty()) {
            std::cerr << "Queue is empty" << std::endl;
            return -1;
        }
        return arr[frontIndex++];
    }

    void push(int x) {
        if (size() >= arr.capacity()) {
            std::cerr << "No space left in the queue" << std::endl;
            return;
        }
        arr.push_back(x);
    }

    int size() const {
        return arr.size() - frontIndex;
    }

    bool isEmpty() const {
        return size() == 0;
    }
};

int main() {
    Queue q(5);
  
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
    
    // Replace the system("pause") with a cross-platform solution.
    std::cin.get();
    return 0;
}
