#include <iostream>
#include <list>

template <typename T>
class Queue {
private:
  std::list<T> data;

public:
  // Конструктор по умолчанию
  Queue() {}

  // Вставка элемента в очередь
  void enqueue(const T& value) {
    data.push_back(value);
  }

  // Извлечение элемента из очереди
  T dequeue() {
    if (empty()) {
      throw std::runtime_error("Queue is empty");
    }
    T value = data.front();
    data.pop_front();
    return value;
  }

  // Просмотр элемента в начале очереди
  T front() const {
    if (empty()) {
      throw std::runtime_error("Queue is empty");
    }
    return data.front();
  }

  // Проверка на пустоту очереди
  bool empty() const {
    return data.empty();
  }

  // Размер очереди
  size_t size() const {
    return data.size();
  }
};

int main() {
  Queue<int> queue;

  // Добавление элементов в очередь
  queue.enqueue(10);
  queue.enqueue(20);
  queue.enqueue(30);

  // Вывод размера очереди
  std::cout << "Size of queue: " << queue.size() << std::endl;

  // Извлечение и вывод элементов из очереди
  std::cout << "Dequeued elements:" << std::endl;
  while (!queue.empty()) {
    std::cout << queue.dequeue() << " ";
  }
  std::cout << std::endl;

  return 0;
}
