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

#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

ll dp[101][1100];
int a[101][10];//if a[i][j]==1 means jth person have ith id shirt
void inti()
{
    loop(i,0,101)
    loop(j,0,1100)
    dp[i][j]=-1;

    loop(i,0,101)
    loop(j,0,11)
    a[i][j]=0;


}
int n;
ll f(int t,int s)
{
    if(t==0&&s==0)
    {
        dp[0][0]=1;
        return 1;
    }
    if(dp[t][s]!=-1)return dp[t][s];
    ll ans=0;
    ans=ans+f(t-1,s);
    loop(i,0,n)
    { // if((1<<i & s)&& a[t][i])
        if(((1<<i)&s)&&a[t][i])
            ans=(ans+f(t-1,s-(1<<i)))%mod;
    }
    dp[t][s]=ans;
    return ans;
}

int main()
{

    frmlty
    {
        inti();
        cin>>n;
        int x;
        char c;
        loop(i,0,n)
        {
            while(true)
            {
                scanf("%d%c",&x,&c);
                a[x][i]=1;
                if(c=='\n')
                    break;
            }

        }
        dp[0][0]=1;
        loop(i,1,1<<n)
        dp[0][i]=0;

        /*       loop(i,1,101)//start giving shirt
               {
                   loop(j,0,1<<n)
                   {
                       dp[i][j]=dp[i-1][j];//j people are wearing i-1 tshirt
                       loop(k,0,n)
                       {
                           if((1<<k & j)&& a[i][k])//if oerson belong to this set and he has ith shirt
                               dp[i][j]=(dp[i][j]+dp[i-1][j-(1<<k)])%mod;//add the ans of subset in which only this kth element is not wearing shirt
                       }
                   }
               }
               cout<<dp[100][(1<<n)-1]<<"\n";

           }*/

        cout<<f(100,(1<<n)-1)<<"\n";
    }
    return 0;
}


