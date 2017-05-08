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

int c=0;
int v1[1001][1001];
int v2[1001][1001];
int a[1005][1005];
int ans[1001][1001];
void f1(int x,int y)
{
    v1[x][y]=1;
    c++;
    if(a[x-1][y]&&v1[x-1][y]==0)f1(x-1,y);
    if(a[x+1][y]&&v1[x+1][y]==0)f1(x+1,y);
    if(a[x][y-1]&&v1[x][y-1]==0)f1(x,y-1);
    if(a[x][y+1]&&v1[x][y+1]==0)f1(x,y+1);
}

int main()
{

    int n,m,q;

    le2(n,m);
    le(q);
    loop(i,1,n+1)
    loop(j,1,m+1)
    le(a[i][j]);

    int tl=0;
    loop(i,1,n+1)
    loop(j,1,m+1)
    {
        if(a[i][j])tl++;
    }

    int x,y;
    int hv;
    int br=0;
    loop(i,0,q)
    {
        le2(x,y);
        if(v1[x][y]==0&&a[x][y]==1)
        {
            c=0;
            f1(x,y);
            tl=tl-c;
        }
        printf("%d\n",tl);
    }
    return 0;
}


