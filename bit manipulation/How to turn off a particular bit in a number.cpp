#include<bits/stdc++.h>
using namespace std;
unsigned int f(unsigned int x,int k)
{
    return (x^((1<<k-1)));
}
main()
{
    cout<<f(15,1);
}
