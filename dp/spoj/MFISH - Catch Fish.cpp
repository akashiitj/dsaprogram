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

int dp[1000000];
int dp1[1000000];


int main()
{
    int n;
    le(n);

    int a[n+1];
    loop(i,1,n+1)
    le(a[i]);

    int m;
    le(m);
    pii p[m+1];

    loop(i,1,m+1)
    {
        le2(p[i].first,p[i].second);

    }
    p[m+1].first=20;

    sort(p+1,p+m+1);

    int cs[n+1];

    cs[0]=0;
    loop(i,1,n+1)
    cs[i]=cs[i-1]+a[i];

    loop(i,1,n+1)
    cout<<cs[i]<<" ";

    cout<<"\n";

    int pre=0;
    int i=1;
    int j1;
    loop(i1,1,25)
    {
        //cout<<i1<<" "<<p[i].first<<"\n";
        if(p[i].first==i1)
        {
            int pos=p[i].first;
            int l=p[i].second;
            //  cout<<pos<<" "<<l<<" "<<p[i+1].first<<" "<<miN(pos+l,p[i+1].first)<<" q1\n";
            loop(j,l+pre,miN(pos+l,p[i+1].first))
            {
                dp1[j]=cs[j]-cs[j-l]+dp[j-l];
                j1=j;
            }
            loop(j,l+pre,miN(pos+l,p[i+1].first))
            {
                dp[j]=dp1[j];
            }

            //cout<<j1<<" "<<miN(pos+l,p[i+1].first)<<" q\n";
            pre=pos;
            i++;
            i1=j1+1;


        }
        else dp[i1]=maX(dp[i1],dp[i1-1]);

        cout<<dp[i1]<<" ";

    }
    cout<<dp[10000];


    return 0;
}

