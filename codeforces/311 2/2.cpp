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
#define lell(x) scanf("%%I64d",&x);
#define le2ll(x,y) scanf("%%I64d%%I64d",&x,&y);


int main()
{
  //  fast;
    double n,w,x;
    cin>>n>>w;
    int n1=n;
    double mi=10000000000,ma=-1;
    int a[2*n1];
    loop(i,0,2*n1)
    {
        //cin>>x;
        le(a[i]);
    }
    sort(a,a+(2*n1));
    cout<<fixed<<setprecision(6);
    mi=(double)a[0];
    ma=(double)a[n1];
    if((mi*2)<ma)
    {
        if(n*(mi+(2*mi))<=w)
        {
            cout<<n*(mi+2*mi)<<"\n";
        }
        else cout<<w<<"\n";

    }
    else if((mi*2)>=ma)
    {
        if(n*(ma+(ma/2))<=w)
        {
            cout<<n*(ma+(ma/2))<<"\n";
        }
        else cout<<w<<"\n";
    }
    return 0;
}
