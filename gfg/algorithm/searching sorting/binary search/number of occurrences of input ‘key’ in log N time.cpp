
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;


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

int a[100];

int main()
{
    int n,l,h,m,ansi,x;
    int lp,rp;
    le(n);
    loop(i,0,n)
    le(a[i]);

    le(x);

    l=0;
    h=n-1;

    while(l<h)
    {
        m=(l+h)/2;

        if(a[m]<x)
            l=m+1;
        else h=m;

    }
    lp=h;
   // cout<<lp<<"\n";
    l=0;
    h=n-1;
    while(l<h)
    {
        m=(l+h+2)/2;//converting into 1 index;

        if(a[m-1]>x)
            h=m-1;
        else l=m;

    }
    rp=l;
    cout<<lp<<" "<<rp<<"\n";
    cout<<rp-lp+1<<"\n";



    return 0;
}

