#include<bits/stdc++.h>
using namespace std;
int f(int n)
{
    return ((n*(n+1)*((2*n)+1))+(3*n*(n+1)))/12;
}
main()
{   int n;
    cin>>n;
    int i=1;
    while(f(i)<=n)i++;
    cout<<i-1<<endl;
}
