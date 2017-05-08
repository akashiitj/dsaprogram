
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

int dp[4001];
int mem[4001]= {};
int a,b,c;
int f(int n)
{
    if(mem[n]!=0)return dp[n];
    if(n<0)return -1;
    if(n==0)return 0;
    int a1=f(n-a);
    int a2=f(n-b);
    int a3=f(n-c);
    if(a1>=0&&a1>=0)dp[n]=max(dp[n],a1+1);
    if(a2>=0&&a2>=0)dp[n]=max(dp[n],a2+1);
    if(a3>=0&&a3>=0)dp[n]=max(dp[n],a3+1);
    mem[n]=1;
    return dp[n];
}

int main()
{
    int n;
    le2(n,a);
    le2(b,c);

    loop(i,1,n+1)
    dp[i]=-1;

    dp[0]=0;

//    loop(i,1,n+1)
//    {
//        if(i-a>=0&&dp[i-a]!=-1)dp[i]=max(dp[i],dp[i-a]+1);
//         if(i-b>=0&&dp[i-b]!=-1)dp[i]=max(dp[i],dp[i-b]+1);
//          if(i-c>=0&&dp[i-c]!=-1)dp[i]=max(dp[i],dp[i-c]+1);
//    }
//    cout<<dp[n]<<"\n";

    cout<<f(n)<<"\n";


    return 0;
}


