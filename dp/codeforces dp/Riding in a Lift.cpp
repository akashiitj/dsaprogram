
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

#define fast      ios_base::sync_with_stdio(false);
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
#define lell(x) scanf(" %I64d",&x);
#define le2ll(x,y) scanf(" %I64d%I64d",&x,&y);

#define F first;
#define S second;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

ll dp[5001][5001]= {};
ll cs[5001]={};
int f(int i,int j)
{
    if(((i+j)%2)==0)return ((i+j)/2)-1;
    return (i+j)/2;
}
int main()

{
    int  n, a, b, k;
    le2(n,a);
    le2(b,k);
    int p;
    if(a<b)
        p=b-1;
    if(a>b)
    {
        p=n-b;
        a=n-a+1;
        b=n-b+1;

    }
 // cout<<   p<<" "<< a<<" "<< b<<" "<< k<<"\n";
    dp[0][a]=1;
    loop(j,1,p+1)
    cs[j]=dp[0][j]+cs[j-1];
    loop(i,1,k+1)
    {
//        loop(j,1,p+1)
//          cout<<cs[j]<<" ";
//          cout<<endl;
        loop(j,1,p+1)
        {
            dp[i][j]=dp[i][j]+cs[j-1];
            dp[i][j]%=mod;
          //  cout<<b<<" "<<j<<" "<<f(b,j)<<" "<<cs[f(b,j)]-cs[j]<<" "<<dp[i][j]<<" d\n";
            dp[i][j]=dp[i][j]+cs[f(b,j)]-cs[j];
            dp[i][j]%=mod;
        }
//         loop(j,1,p+1)
//          cout<<dp[i][j]<<" ";
//          cout<<endl<<"\n";
        loop(j,1,p+1)
         cs[j]=dp[i][j]+cs[j-1];
    }

   ll ans=0;
   loop(j,1,p+1)
   ans=(ans+dp[k][j])%mod;
   cout<<ans<<"\n";

    return 0;
}


