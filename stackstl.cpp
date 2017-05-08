// stack::push/pop
#include <iostream>       // std::cout
#include <stack>          // std::stack

int main ()
{
  std::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);
//  std::cout<<find(mystack.begin(), mystack.end(), myValue);
  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
    // std::cout << ' ' << mystack.top();
    std::cout << mystack.pop();
  }
  std::cout << '\n';

  return 0;
}
