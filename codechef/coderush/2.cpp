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

int dp[51][51][51][51][2];
int m[51][51][51][51][2];

int isl(int i,int j)
{
    if(i<0||j<0)return 0;
    return 1;
}

int f(int i,int j,int x,int y,int p)
{


    int &r=dp[i][j][x][y][p];

    if(r!=-1)return r;


    if(isl(i-2,j-1)&&f(i-2,j-1,x,y,1-p)==p)return r=p ;

    if(isl(i-1,j-2)&&f(i-1,j-2,x,y,1-p)==p)return r=p ;

    loop(j1,0,x+1)
    {
        if(p==f(i,j,j1,y,1-p))return r=p ;
    }

    loop(j1,0,y+1)
    {
        if(p==f(i,j,x,j1,1-p))return r=p ;
    }


    for (int i = min(x, y); i > 0; --i)
    {
        if(p==f(i,j,x-i,y-i,1-p))return r=p ;
    }
   // m[i][j][x][y][p]=1;

    //cout<<i<<" "<<j<<" "<<x<<" "<<y<<" "<<p<<" "<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<" "<<a5<<" " <<dp[i][j][x][y][p]<<"\n";


    return r=1-p;
}


int main()
{

    int i,j,x,y;
    memset(dp,-1,sizeof dp);
    frmlty
    {
        le2(i,j);
        le2(x,y);

        if(f(i,j,x,y,0)==0)
        {
            printf("WIN\n");
            //cout<<"WIN\n";
        }
        else
            printf("LOSE\n");
            //cout<<"LOSE\n";

    }
    return 0;
}
