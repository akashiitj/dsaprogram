#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

#define fast      ios_base::sync_with_stdio(false);
#define frmlty     int test_case;cin<<test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<ll>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair

#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i<=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf(" %I64d",&x);
#define le2ll(x,y) scanf(" %I64d%I64d",&x,&y);

#define F first;
#define S second;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

int main()
{
    int x,y,a,b,c,d;
    le2(x,y);
    le2(a,b);
    le2(c,d);
    if(a+c <= x &&maX(b,d)<=y)
        cout<<"YES\n";
    else if(a+c <= y &&maX(b,d)<=x)
        cout<<"YES\n";

    else if(a+d <= x &&maX(b,c)<=y)
        cout<<"YES\n";
    else if(a+d <= y &&maX(b,c)<=x)
        cout<<"YES\n";

    else if(b+c <= x &&maX(a,d)<=y)
        cout<<"YES\n";
    else if(b+c <= y &&maX(a,d)<=x)
        cout<<"YES\n";

    else if(b+d <= x &&maX(a,c)<=y)
        cout<<"YES\n";
    else if(b+d <= y &&maX(a,c)<=x)
        cout<<"YES\n";

    else cout<<"NO\n";

    return 0;
}


