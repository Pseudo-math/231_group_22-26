#include <iostream>
#include <cstdlib>
#include <clocale>
#include <stack>
using namespace std;
int main()
{
  return EXIT_SUCCESS;
}

      
int PostfixOperations(string str)
{
    Stack<string> buffer = new Stack<string>();
    Stack<int> result = new Stack<int>();
    string temp = "";
    char[] operations = {'+', '*', '-', '/', '='};
    for (int i = str.Length - 1; i >= 0; --i)
    {
      if (Char.IsDigit(str[i]))
      {
          temp = str[i] + temp;
          if (i == 0) buffer.Push(temp);
      }
      else if (str[i] == ' ' && temp != "")
      {
          buffer.Push(temp);
          temp = "";
      }
      else foreach (char j in operations)
      {
          if (str[i] == j)
          {
              buffer.Push(str[i].ToString());
              break;
          }
      }
    }
    for (int i = buffer.Size(); i > 0; --i)
    {
        temp = buffer.Pop();
        int number;
        if (int.TryParse(temp, out number)) result.Push(number);
        else if (temp == "=") return result.Pop();
        else
        {
            int numberSecond = result.Pop(), numberFirst = result.Pop();
            if (i == "+") result.Push(numberFirst + numberSecond);
            if (i == "-") result.Push(numberFirst - numberSecond);
            if (i == "*") result.Push(numberFirst * numberSecond);
            if (i == "/") result.Push(numberFirst / numberSecond);
        }
    }
    return default(int);
}
      
