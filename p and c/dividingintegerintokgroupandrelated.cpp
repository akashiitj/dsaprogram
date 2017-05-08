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

#define F first
#define S second

//ways to make up n sum using some element but element cant be >m
int p (int n, int m)//ways to diivide n into m group or m places places are similar and place may be empty also

{
    if(n<0||m<0)return 0;

  //  if(n==0&&m>=0)return 1;

    if(n>=0&&m==1)return 1;
    else if(m>=1&&n==1)return 1;

    return p(n, m - 1) + p(n - m, m);

}

int dp[100][100]={};//ways to write n as sum of numbers smaller or = than m


void bottomup(int n,int m)
{
    loop(i,0,m+1)
    dp[0][i]=1;

    loop(i,1,n+1)
    {
        loop(j,1,m+1)
        {
            dp[i][j]=dp[i][j-1];//sum of numbers smaller or
            if(i>=j) dp[i][j]+=dp[i-j][j];// = than m
   //         cout<<dp[i][j]<<" ";
        }
 //       cout<<"\n";

    }
    cout<<dp[n][m]<<"\n";
}



//ways to diivide n into m group or m places places are similar and place must not be empty
ll f(ll n,ll k)
{
    if(n<0||k<0)return 0;
    if(n==0&&k==0)
        return 1;
    if(n==0&&k>0)//in each group atleast 1 is thier
        return 0;
    if(n>=1&&k<=0)return 0;//each coin must be in some group
    dp[n][k]=f(n-1,k-1)+f(n-k,k);
    return dp[n][k];
}

int main(){
    bottomup(6,3);
    cout<<p(6,3);
    return 0;
}

