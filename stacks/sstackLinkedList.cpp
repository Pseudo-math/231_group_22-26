#include <vector>
#include <iostream>
using namespace std;
struct Stack {
    int size;
    forward_list <int> elements;

    Stack()
    {
       //elements = new vector <int>;
       //size = 0;
    } 

    int Size() 
    {
       return size;
    }

    int Pop()
    {
       if (size != 0)
       {
           int result = elements[size - 1];
           elements.erase(elements.begin() + size - 1);
           --size;
           return result;
       }
       return 0;
    }
	  
    void Push(int val)
    {
       elements.push_front(val);
    }

    bool IsEmpty()
    {
      return (size == 0);
    }
};
bool test(){
          Stack *arr = new Stack;
          for (int i = 0; i < 16; ++i)
          {
              arr->Push(i);
              if (arr->Size() != i+1) return false;
          }
          if (arr->elements[arr->Size()-1] != 15) return false;
          for (int i = 15; i >= 0; --i)
          {
              if (arr->Pop() != i) return false;
          }
          if (arr->Size() != 0) return false;
          return true;
}
int main(){
         cout << test();
}


