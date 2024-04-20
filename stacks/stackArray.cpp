#include <vector>
#include <iostream>
using namespace std;
struct Stack {
    //int size;
    vector< int > elements;

    Stack()
    {
       //elements = new vector <int>;
        //size = 0;
    } 

    int Size() 
    {
       return elements.size();
    }

    int Pop()
    {
       if (elements.size() != 0)
       {
           int result = elements[elements.size() - 1];
	       elements.erase(elements.begin() + elements.size() - 1);
           return result;
       }
       return 0;
    }
	  
    void Push(int val)
    {
       elements.push_back(val);
    }

    bool IsEmpty()
    {
      return (elements.size() == 0);
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


