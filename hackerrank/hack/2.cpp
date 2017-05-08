
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

queue<int> q[100001];

int main()
{
    int n,k,t;
    le2(n,k);
    le(t);

    string s;
    cin>>s;

    loop(i,0,n)
    {
        int pn=i%k;
        if(s[i]=='1')q[pn].push(i);
    }

    loop(i,0,n)
    {
        int pn=i%k;
        if(s[i]=='1')
        {
            q[pn].pop();
            continue;
        }
        if(s[i]=='0')
        {
            if(q[pn].size()==0)
                continue;

            int rt=(q[pn].front()-i)/k;
            if(rt<=t)
            {
                t=t-rt;
                s[i]='1';
                s[q[pn].front()]='0';
                q[pn].pop();
            }
        }
    }
    cout<<s<<"\n";
    return 0;
}

