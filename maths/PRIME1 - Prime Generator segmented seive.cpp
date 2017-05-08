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

bool a[10000001];
bool x[10000001];

int main()
{
    int m,n;

    frmlty
    {
        le2(m,n);
        memset(x,0,sizeof(x));
        if(m==1)m++;
        if(n==1)n++;
        for(int i=2; i*i<=n; i++)
        {
            if(a[i]==0)
            {
                for(int j=maX((m/i)*i,i*i); j<=n; j=j+i)
                {

                    if(j<10000000)  a[j]=1;
                    if(j>=m) x[j-m]=1;
                }
            }
        }

        loop(j,0,n-m+1)
        if(x[j]==0)printf("%d\n",j+m);

        //printf("\n");
    }
    return 0;
}
