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

int p[1000001];
int a[1000001];

int main()
{   int n,x;
    while(true)
    {
        le(n);
        if(n==0)
            break;
        loop(i,1,n+1)
        {
            le(x);
            a[i]=x;
            p[x]=i;
        }
  int fl=0;
        loop(i,1,n+1)
        {
            if(a[i]!=p[i])
            {  fl=1;
                printf("not ambiguous\n");
              break;
            }
        }
       if(fl==0)  printf("ambiguous\n");
    }
    return 0;
}

