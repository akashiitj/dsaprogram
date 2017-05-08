
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

int p[15];
int a[15];
int n;
int ans;
int mark[50];

void perm(string s)
{
    if(s.length()==min(8,n))
    {
        int px=0;
        loop(i,2,n)
        px=px+(a[s[i]-'0']^a[s[i-1]-'0']^a[s[i-2]-'0'])*p[i];

        ans=miN(ans,px);


    }
    for(int i=0;i<min(8,n);i++)
    {
        if(mark[i]==0)
        {
        mark[i]=1;
        perm(s+(char)(i+'0'));
        mark[i]=0;

        }


    }
}

int main()
{
    frmlty
    {
      le(n);
      ans=INT_MAX;
      loop(i,0,n)
      {
          le(a[i]);
      }
      loop(i,0,n)
      {
          le(p[i]);
      }
      memset(mark,0,sizeof(mark));
      perm("");
      cout<<ans<<"\n";
    }
    return 0;
}

