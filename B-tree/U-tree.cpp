#include <iostream>

using namespace std;

struct UNode {
  int data;
  UNode* left;
  UNode* right;
  UNode* parent;

  UNode(int d, UNode* l = nullptr, UNode* r = nullptr, UNode* p = nullptr) :
    data(d), left(l), right(r), parent(p) {
    if (l != nullptr) l->parent = this;
    if (r != nullptr) r->parent = this;
  }
};

void printTree(UNode* root, int indent = 0) {
  if (root == nullptr) return;

  printTree(root->right, indent + 3);
  for (int i = 0; i < indent; ++i) {
    cout << ' ';
  }
  cout << root->data << endl;
  printTree(root->left, indent + 3);
}

struct UTree {
  UNode* root;

  UTree(UNode* p) : root(p) {}

  void print() {
    printTree(root);
  }

  void deleteNode(UNode* node) {
    if (node == nullptr) return;

    UNode* parent = node->parent;
    UNode* child = nullptr;
    if (node->left != nullptr) {
      child = node->left;
    } else if (node->right != nullptr) {
      child = node->right;
    }

    if (parent == nullptr) {
      root = child;
      if (child != nullptr) {
        child->parent = nullptr;
      }
      return;
    }

    if (parent->left == node) {
      parent->left = child;
    } else {
      parent->right = child;
    }

    if (child != nullptr) {
      child->parent = parent;
    }
  }

  void rotateLeft() {
    UNode* prevRoot = root;
    UNode* rightNode = root->right;
    UNode* leftNode = root->left;

    prevRoot->right = rightNode->left;
    if (rightNode->left != nullptr) {
      rightNode->left->parent = prevRoot;
    }

    root = rightNode;
    root->parent = nullptr;
    prevRoot->parent = root;
    root->left = prevRoot;
  }
};

int main() {
  UNode* p10 = new UNode(10);
  UNode* p9 = new UNode(9, nullptr, p10);
  UNode* p8 = new UNode(8);
  UNode* p7 = new UNode(7);
  UNode* p6 = new UNode(6);
  UNode* p5 = new UNode(5, p8, p9);
  UNode* p4 = new UNode(4);
  UNode* p3 = new UNode(3, p6, p7);
  UNode* p2 = new UNode(2, nullptr, p5);
  UNode* p1 = new UNode(1, p2, p3);

  UTree t(p1);
  t.print();
  cout << "================" << endl;
  t.deleteNode(p7);
  t.print();

  // Очистка памяти (не забудьте удалить все узлы!)
  delete p10;
  delete p9;
  delete p8;
  delete p7;
  delete p6;
  delete p5;
  delete p4;
  delete p3;
  delete p2;
  delete p1;

  return EXIT_SUCCESS;
}

