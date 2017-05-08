#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;
const int N = 10000001;
const int mod = 1000000009;

int a[1001];
int main()
{
    std::ios_base::sync_with_stdio(false);
    int t1;
    cin>>t1;
    ull r=1,u,v,t,n;
    while(t1--)
    {   r=1;
        cin>>n;
        loop(i,0,n)
        cin>>a[i];
        cin>>u>>v;
        sort(a,a+n);
        loop(i,u-1,v)
        {
            r=r*a[i];
            if(r>=mod)r=r%mod;
        }
        cout<<r<<endl;

    }
    return 0;
}

