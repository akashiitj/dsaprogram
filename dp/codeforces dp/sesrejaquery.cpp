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
int ht[100001]= {};
int a[100001];
int dp[100002];
int main()
{
    int n,q;
    le2(n,q);
    loop(i,1,n+1)
    le(a[i]);
    dp[n+1]=0;
    for(int i=n; i>=1; i--)
    {
        dp[i]=dp[i+1]+(ht[a[i]]==0);
        ht[a[i]]++;
    }
    int l,r;
    loop(i,0,q)
    {
        le(l);
        printf("%d\n",dp[l]);
    }
    return 0;
}

