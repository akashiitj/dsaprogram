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
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

 int a[1000000];
    int dp[1000000];

int main()
{
    string s;
    int c,n;

    frmlty
    {
        c=0;
        cin>>s;
        n=s.length();
        loop(i,0,n)
        {
            if(s[i]=='R')
            {
                a[i]=-1;
                c++;
            }
            else a[i]=1;
        }
        int maxupto=max(0,a[0]);
        dp[0]=maxupto;
        loop(i,1,n)
        {
            maxupto=maxupto+a[i];
            dp[i]=max(dp[i-1],maxupto);
            if(maxupto<0)maxupto=0;
        }
        if(c==n)cout<<c-1<<"\n";//first you forget this
       else cout<<c+dp[n-1]<<"\n";//R are not countin double time because when r is flipped we do -1 which means -1 from c
    }
    return 0;
}


