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

int ismor(ll n1, ll n2)
{
    int flag=1;
    while(n1>0 && n2>0)
    {
        int a = (n1%10);
        int b = (n2%10);
        if(a!=b)
        {
            flag=0;
            break;
        }
        n1/=10;
        n2/=10;
    }
    if(flag)return 1;
    else return 0;
}
int main()
{
    int n,q,a[10010];
    le2(n,q);
    for(int i=0; i<n; i++)
    {
        ll temp;
        lell(temp);
        if(ismor(temp,temp*temp)==1)a[i]=1;
        else a[i]=0;
    }
    while(q--)
    {
        ll f,g,h;
        le2ll(f,g);
        lell(h);
        if(f==2)
        {
            int cnt=0;
            for(int i=g; i<=h; i++)
            {
                if(a[i]==1)cnt++;
            }
            printf("Automorphic: %d\n",cnt);
        }
        else if(f==1)
        {
            int cnt=0;
            for(int i=g; i<=h; i++)
            {
                if(a[i]==0)cnt++;
            }
            printf("Non Automorphic: %d\n",cnt);
        }
        else
        {
            if(ismor(h,h*h))a[g]=1;
            else a[g]=0;
        }
    }
    return 0;

}
