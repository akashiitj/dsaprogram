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

char c[1001][1001];
int x[1001][1001];
int y[1001][1001];

int main()
{
    int n;
    frmlty
    {
        le(n);
        loop(i,0,n)
        loop(j,0,n)
        cin>>c[i][j];
        int b=1;
        for(int i=0;i<n;i++)
        {
            b=1;
            for(int j=n-1;j>=0;j--)
                if(c[i][j]=='.')x[i][j]=b;
                else
                {
                    x[i][j]=0;
                    b=0;
                }
        }
        int ans=0;
        for(int j=0;j<n;j++)
        {   b=1;
            for(int i=n-1;i>=0;i--)
            {
                if(c[i][j]=='.'&&x[i][j]==1)
                {
                    ans++;

                }
                if(c[i][j]=='#')
                    break;

            }
        }
        cout<<ans<<"\n";
    }
   return 0;
}

