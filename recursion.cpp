#include<iostream>
using namespace std;
int func(int i)
{
    if(i==0)return 0;
   cout<<func(i-1)<<endl;
    return i;
}
main()
{
    func(10);
}

