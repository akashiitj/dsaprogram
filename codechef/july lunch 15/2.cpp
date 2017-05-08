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

bool dp[10000][10000][2];
bool m[10000][10000][2]={false};

bool f(int a,int b,int hv)
{
    if(m[a][b][hv]==true)return dp[a][b][hv];
    m[a][b][hv]=true;
    if(a==1&&b==1)return dp[a][b][hv]=1-hv;

    loop(i,1,1+1)
    if(f(a-i,i,1-hv)==hv)return dp[a][b][hv]=hv;



    return dp[a][b][hv]=1-hv;
}

int main()
{
    int a,b;
    frmlty
    {
        le2(a,b);
//        loop(i,0,a+1)
//        loop(j,0,b+1)
//        {m[i][j][0]=0;m[i][j][1]=0;}
        if(a<b)swap(a,b);
        if(f(a,b,0)==0)
            printf("Tuzik\n");
        else printf("Vanka\n");
    }
    return 0;
}


