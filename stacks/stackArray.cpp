struct Stack {
    int size;
    vector< int > elements;

    Stack()
    {
       elements = new vector <int>;
       size = 0;
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
       arr.push_back(val);
       ++size;
    }

    bool IsEmpty()
    {
      return (size == 0);
    }
   }

}


