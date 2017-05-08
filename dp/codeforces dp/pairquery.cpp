
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
    string s;
    cin>>s;
    int n=s.length();
    int dp[n+1];
    dp[0]=0;
    dp[1]=0;
    loop(i,2,n+1)
    {
        dp[i]=dp[i-1]+(s[i-1]==s[i-2]);
      //  cout<<dp[i]<<" ";
    }
    //cout<<"\n";
    int q;
    le(q);
    int l,r;
    loop(i,0,q)
    {
        le2(l,r);
        printf("%d\n",dp[r]-dp[l]);
    }
    return 0;
}

