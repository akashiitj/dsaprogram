#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;
const int N = 10000001;
const int mod = 1000000007;


int main()
{
    ll n,t;
    cin>>n>>t;
    ll a[n-1];
    loop(i,0,n-1)
    cin>>a[i];
    ll t1=1;
    while(true&&t1!=n)
    {
        t1=t1+a[t1-1];
        if(t1==t)
        {cout<<"YES"<<endl;
        return 0;}
    }
    if(t1==n&&t==n)
        {cout<<"YES"<<endl;
        return 0;}
    cout<<"NO"<<endl;
    return 0;
}

