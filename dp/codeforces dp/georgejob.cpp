
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

ll dp[5001][5001];//n elements k chunks

int main()
{
    int n,siz,k;
    le2(n,siz);
    le(k);
    int a[n+1];
    ll cs[n+1];
    cs[0]=0;

    loop(i,1,n+1)
    {
        le(a[i]);
        cs[i]=cs[i-1]+(ll)a[i];
    }


   // dp[0][0]=0;


    loop(i,1,n+1)
    {
       loop(j,1,k+1)
       {
           dp[i][j]=dp[i-1][j];
           if(i<siz)dp[i][j]=0;
           else
           {
               dp[i][j]=maX(dp[i][j],cs[i]-cs[i-siz]+dp[i-siz][j-1]);
           }
         // cout<<dp[i][j]<<" ";
       }
       //cout<<"\n";
    }
    cout<<dp[n][k]<<"\n";

    return 0;
}


