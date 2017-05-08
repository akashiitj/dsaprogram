
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

priority_queue<pii,vector<pii >,greater<pii > > mi;//min priority q of pair


int f(string s)
{
    int x=s[0]-'0';
    x=x*10+s[1]-'0';
    x=x*pow(10,s[3]-'0');
    return x;
}

int main()
{
    int a[31];
    a[0]=1;
    a[1]=2;
    loop(i,2,31)
    a[i]=a[i-1]*2;
    int n,i,ans;
    string str;
    while(true)
    {   cin>>str;
        if(str=="00e0")
        break;
        n=f(str);
        i=0;
        while(!(n>=a[i]&&n<a[i+1]))
            i++;
        ans=((n-a[i])*2)+1;
        printf("%d\n",ans);
    }
    return 0;
}

