
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

int dp[1001][1001][2];
int mem[1001][1001][2]= {};

int f(int a,int b,int p)
{
    if(mem[a][b][p]!=0)return dp[a][b][p];
    if(a==1&&p==0)return dp[a][b][p]=1-p;
    if(b==1&&p==1)return dp[a][b][p]=1-p;
    mem[a][b][p]=1;
    int a1=-1,a2=-1;
    if(p==0)
    {
        a1=f(a,b-1,1-p);
        if(gcd(a,b)>1)
            a2=f(a,b/gcd(a,b),1-p);
        if(a1==0||a2==0)return dp[a][b][p]=0;
        else return dp[a][b][p]=1;
    }
    else if(p==1)
    {
        a1=f(a-1,b,1-p);
        if(gcd(a,b)>1)
            a2=f(a/gcd(a,b),b,1-p);
        if(a1==1||a2==1)return dp[a][b][p]=1;
        else return dp[a][b][p]=0;
    }

}
int main()
{
    int a,b,winner;
    frmlty
    {
        le2(a,b);
        if(a==1&&b==1)printf("Draw\n");
        else  if(b==1)
            printf("Arjit\n");
        else if(a==1)
            printf("Chandu Don\n");
        else{
            winner=f(a,b,0);
            if(winner==0)
                printf("Arjit\n");
            else printf("Chandu Don\n");
        }
    }
    return 0;
}

