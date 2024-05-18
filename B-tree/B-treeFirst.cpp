struct BNode
{
int data; // элемент данных
BNode* left, * right; // указатели на сыновей
BNode(int d, BNode* l = nullptr, BNode* r = nullptr) :
data(d), left(l), right(r) {} // конструктор
};
