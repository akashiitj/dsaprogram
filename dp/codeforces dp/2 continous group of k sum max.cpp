

#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

#define fast      ios_base::sync_with_stdio(false);
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
#define lell(x) scanf(" %I64d",&x);
#define le2ll(x,y) scanf(" %I64d%I64d",&x,&y);

ll a[200001];
ll dpf[200001];
ll dpb[200001];
int fi[200001];
int bi[200001];

ll csf[200001];
ll csb[200001];

int main()
{
    ll n,k;
    le2ll(n,k);
    loop(i,1,n+1)
    lell(a[i]);

    csf[0]=0;
    loop(i,1,n+1)
    csf[i]=csf[i-1]+a[i];

    csb[n+1]=0;
    for(int i=n; i>=0; i--)
    {
        csb[i]=csb[i+1]+a[i];
    }

    dpf[0]=0;
    loop(i,k,n+1)
    {
        if(csf[i]-csf[i-k]>dpf[i-1])
        {
            dpf[i]=csf[i]-csf[i-k];
            fi[i]=i-k+1;
        }
        else
        {
            dpf[i]=dpf[i-1];
            fi[i]=fi[i-1];
        }
    }
    for(int i=n-k+1; i>=1; i--)
    {
        if(csb[i]-csb[i+k]>=dpb[i+1])
        {
            dpb[i]=csb[i]-csb[i+k];
            bi[i]=i;
        }
        else
        {

            dpb[i]=dpb[i+1];
            bi[i]=bi[i+1];
        }


    }

    ll ans=0;
    int ansi;
    for(int i=k; i<=n-k; i++)
    {
        if(ans<dpf[i]+dpb[i+1])
        {
            ans=dpf[i]+dpb[i+1];
            ansi=i;
        }
    }
    cout<<fi[ansi]<<" "<<bi[ansi+1]<<"\n";
}


