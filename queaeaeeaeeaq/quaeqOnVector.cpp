#include <iostream>
#include <vector>

template <typename T>
class Queue {
private:
    std::vector<T> elements;

public:
    Queue() {}
    ~Queue() 
    {
        vector<T>().swap(elements);
    };
    void Enqueue(const T item) {
        elements.insert(elements.begin(), item);
    };

    T Dequeue() {
        if (!elements.empty()) {
            T result = elements.back();
            elements.pop_back();
            return result;
        }
        return T(); 
    };
    int IsEmpty()
    {
        return elements.empty();
    }; 
    Size() const 
    {
        return elements.size();
    };
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
