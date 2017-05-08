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

#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

int comp[10001];
int sc[10001];

int findc(int x)
{
    int i=x,j;
    while(comp[x]!=x)
        x=comp[x];
    while(i!=x)//path compressor
    {
        j=comp[i];
        comp[i]=x;
        i=j;

    }
    return x;
}

void uni(int x,int y)
{
    int cx=findc(x);
    int cy=findc(y);
    if(cx==cy)printf("Invalid query!\n");
    if(sc[cx]>sc[cy])
        comp[cy]=comp[cx];
    if(sc[cx]<sc[cy])
        comp[cx]=comp[cy];

}

int main()
{
    int n,q,type,x,y,cx,cy;
    frmlty
    {

        le(n);
        loop(i,1,n+1)
        {
            le(sc[i]);
            comp[i]=i;
        }

        le(q);

        loop(i,0,q)
        {
            le(type)
            if(type==0)
            {
                le2(x,y);
                uni(x,y);
            }
            if(type==1)
            {
                le(x);
                printf("%d\n",findc(x));
            }

        }



    }
    return 0;
}

