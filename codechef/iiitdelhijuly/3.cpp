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

#define F first
#define S second

int main()
{
    string s;
    cin>>s;
    int n=s.length();
    char c=s[0];
    vi v[2];
    loop(i,1,n)
    {
        if(c==s[i])
            v[0].pb(i);
    }
    int cu=0,pre=1;
    int pl=0;
    if(v[0].size()!=0)pl=1;
    int hv;
    loop(i,1,n-1)
    {   hv=v[cu].size();
        loop(j,0,hv)
        {
            if((v[cu][j]+i<n)&&s[i]==s[v[cu][j]+i])
                v[pre].pb(v[cu][j]);
        }
        if( v[pre].size()==0)
            break;
        pl++;
        swap(cu,pre);
        v[pre].clear();
    }

    if(pl==0||v[cu].size()<2)
        cout<<"NO\n";
    else
    {
        cout<<"YES\n"<<v[cu][0]<<"\n";

    }
    return 0;
}


