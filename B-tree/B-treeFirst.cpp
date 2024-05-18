#include <iostream>

struct BNode {
    int data; // элемент данных
    BNode* left, *right; // указатели на сыновей
    BNode(int d, BNode* l = nullptr, BNode* r = nullptr) :
        data(d), left(l), right(r) {} // конструктор
};

BNode* findLeftGrandson(BNode* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return nullptr; // У корня нет детей, значит нет и внуков
    }
    
    if (root->left != nullptr) {
        if (root->left->left != nullptr) {
            return root->left->left; // Левый сын имеет левого сына (левый внук)
        } else if (root->left->right != nullptr) {
            return root->left->right; // Левый сын имеет правого сына (тоже левый внук)
        }
    }

    if (root->right != nullptr) {
        if (root->right->left != nullptr) {
            return root->right->left; // Правый сын имеет левого сына (тоже левый внук)
        }
        else if (root->right->right != nullptr)
            return root->right->right;
    }

    return nullptr; // Если дошли до сюда, значит у корня нет левых внуков
}
BNode* LeftRotate(BNode* root) {
    if (root == nullptr || (root->right == nullptr)) {
        return root;
    }
    BNode* rootSon = root->right;
    root->right = rootSon->left;
    rootSon->left = root;
    return rootSon;
}

int main() {
    // Создайте примерное дерево для тестирования
    BNode* root = new BNode(1);
    root->left = new BNode(2);
    root->right = new BNode(3);
    root->left->left = new BNode(4);
    root->left->right = new BNode(5);

    BNode* grandson = findLeftGrandson(root);

    if (grandson != nullptr) {
        std::cout << "Самый левый внук: " << grandson->data << std::endl;
    } else {
        std::cout << "У корня нет левых внуков" << std::endl;
    }

    // Освободите память (не забудьте про динамически выделенные узлы)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
