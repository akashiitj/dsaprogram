
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

int a[5][5]={
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };
int vis[10][10];
int c=0;
int m,n;

void dfs(int x,int y)
{
    vis[x][y]=1;
    loop(i,-1,2)
    loop(j,-1,2)
    {
        if(x+i>=0&&y+j>=0&&x+i<m&&y+j<n&&vis[x+i][y+j]==0&&a[x+i][y+j])//you are making mistake here
            dfs(x+i,y+j);

    }
}

int main()
{

    le(n);
    m=n;

    loop(i,0,n)loop(j,0,n)
    {
        if(vis[i][j]==0&&a[i][j])
        {
            c++;
            dfs(i,j);
        }
    }
    cout<<c;
    return 0;
}

