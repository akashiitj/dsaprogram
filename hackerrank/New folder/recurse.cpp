
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

string s;
map<string,int > m;

void f(int i,string ans,vector<char> stc)
{
    if(ans.size()==s.size())
    {
        m[ans]++;
        return;
    }
    if(i<s.size())
    {
        stc.push_back(s[i]);
        f(i+1,ans,stc);
        stc.pop_back();
    }
    if(stc.size()>0)
    {   ans=ans+stc.back();
        stc.pop_back();
        f(i,ans,stc);
    }
}

int main()
{
    cin>>s;
    vector<char > v;
    f(0,"",v);
    cout<<m[s]<<" "<<m.size()<<"\n";
    return 0;
}

