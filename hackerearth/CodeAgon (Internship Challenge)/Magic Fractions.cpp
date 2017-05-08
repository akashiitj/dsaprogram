
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

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

#define F first
#define S second
int isp[501];

void seive()
{
    isp[1]=1;
    for(int i=2; i*i<=500; i++)
    {   if(isp[i]==0)
        for(int j=i*i; j<=500; j=j+i)
            isp[j]=1;
    }

}

ll dp[501];

int main()
{   seive();
  ll sum=0;
    dp[1]=0;
    dp[2]=1;
    int n;
     le(n);
     if(n>=2)
        sum=1;
    loop(i,3,n+1)
    {
        if(isp[i]==0)
        {
            dp[i]=2*dp[i-1];
        }
        else
            dp[i]=dp[i-1];

            sum=sum+dp[i];

    }



    cout<<sum<<"\n";
    return 0;
}

