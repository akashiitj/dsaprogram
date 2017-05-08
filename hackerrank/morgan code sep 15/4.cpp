
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

int bck[300][100002];
int mx[300];
int a[100001];
int n,m,l,k;
int mxbn;
int sz=400;

void f()
{
    //cout<<n<<" n\n";
    loop(i,0,n)
    {
        bck[i/sz][a[i]]++;

    }
    mxbn=(n/sz)+1;
    //cout<<mxbn<<" m\n";
    for(int j=100000; j>=1; j--)
    {
        loop(i,0,mxbn)
        {
            bck[i][j]+=bck[i][j+1];
        }
    }
}

int main()
{

    le2(n,m);

    loop(i,0,n)
    le(a[i]);

    f();

    //cout<<"c\n";

    int ge=0;
    loop(i,0,m)
    {
        ge=0;
        int pge=0;
        le2(l,k);
        loop(j,0,mxbn)
        {
            pge=ge;
            ge=ge+bck[j][l];
           // cout<<pge<<" "<<ge<<" e\n";
            if(ge>=k)
            {
                int c=k-pge;
                int si=j*sz;
                while(c>0)
                {
                    if(a[si++]>=l)c--;
                    if(c==0)printf("%d\n",a[si-1]);
                }
                break;

            }

        }
    }

    return 0;
}

