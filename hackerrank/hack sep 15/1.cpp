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



int main()
{
    string s1,s2;
    cin>>s1>>s2;
    if(s1.length()!=s2.length())
    {
        cout<<-1<<"\n";
        return 0;
    }
    int x1=0,x2=0,ans=0;
    loop(i,0,s1.length())
    {
        if(s1[i]=='0')x1++;
        if(s2[i]=='0')x2++;
        if(s1[i]!=s2[i])ans++;
    }

    if(x1!=x2)
    {
        cout<<-1<<"\n";
        return 0;
    }
    cout<<ans/2<<"\n";


    return 0;
}


