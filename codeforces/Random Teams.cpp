#include<bits/stdc++.h>
using namespace std;
unsigned long long f(unsigned long long n)
{   if(n==1)return 0;
    if(n==2)return 1;
    return (n*(n-1))/2;
}
unsigned long long poww(unsigned long long a, unsigned long long b)
{   if(b==0)return 0;
    unsigned long long res = a;
    for(unsigned long long i = 1; i<b; ++i)
        res += a;

    return res;
}
main()
{
    unsigned long long n,m;
    cin>>n>>m;
    unsigned long long q=n/m;
    unsigned long long mod=n%m;
    cout<<poww(f(q+1),mod)+poww(f(q),m-mod)<<" ";
    cout<<f(n-m+1)<<endl;

}
