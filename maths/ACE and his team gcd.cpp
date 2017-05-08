
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

int ht[2000001];

int main()
{   int n,x;
    int mx=1;
    int c=0;
    int j,aj;
    frmlty
    {
        le(n);
        mx=1;
        memset(ht,0,sizeof(ht));
        loop(i,0,n)
        {
            le(x);
            ht[x]++;
            mx=maX(mx,x);
        }
      //  cout<<mx<<"\n";
        for(int i=mx;i>=1;i--)
        {
            c=0;
            for(j=i;j<=mx;j=j+i)
            {
               c=c+ht[j];

            }
            if(c>=2)
            {
                cout<<i<<"\n";
                break;
            }
        }
    }
    return 0;
}

