
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;


#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<ll>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair

#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);


#define F first
#define S second

int main()
{
    int n;
    le(n);
    int a[n];
    loop(i,0,n)
    le(a[i]);
    int c=0;
    loop(i,0,n)
    {
        if(a[i]==1)
        {
            a[i]=-1;
            c++;
        }
        else a[i]=1;
    }
    int dp[n];
    int maxupto=max(0,a[0]);
    dp[0]=maxupto;
    if(c==n)cout<<n-1<<"\n";
    else{
    loop(i,1,n)
    {
        maxupto=maxupto+a[i];
        dp[i]=max(maxupto,dp[i-1]);
        if(maxupto<0)maxupto=0;
    }

    cout<<c+dp[n-1]<<"\n";
    }

    return 0;
}


