#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1010000007;


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

int dp[101][101][101][2];//i,j,k number of piles hai and chance is of p then who will win p or 1-p
int memo[101][101][101][2]= {};

int f(int a,int b,int c,int p)
{
    if(a<0||b<0||c<0)return -1;
    if(memo[a][b][c][p]!=0)return dp[a][b][c][p];
    if(a==0&&b==0&&c==0)return 1-p;


    int v1,v2,v3,v4,v5,v6,v7;
    memo[a][b][c][p]=1;
    v1=f(a-1,b,c,1-p);
    v2=f(a,b-1,c,1-p);
    v3=f(a,b,c-1,1-p);
    v4=f(a-1,b-1,c,1-p);
    v5=f(a-1,b,c-1,1-p);
    v6=f(a,b-1,c-1,1-p);
    v7=f(a-1,b-1,c-1,1-p);

    if(v1==p||v2==p||v3==p||v4==p||v5==p||v6==p||v7==p)
        return dp[a][b][c][p]=p;

    return dp[a][b][c][p]=1-p;

}

int main()
{
    int a,b,c;
    int ans;
    frmlty
    {
        le2(a,b);
        le(c);
        ans=f(a,b,c,0);

        if(ans==0)//The player who played first
            printf("Ashima\n");
        else//The second player
            printf("Aishwarya\n");

    }
    return 0;
}

