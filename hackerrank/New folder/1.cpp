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

ll a[100001];
ll dp[8000][8000];

ll mult(ll a, ll b, ll k)
{
    if(b==0)return 0;
    ll res = mult(a,b/2,k);
    ll ans = (2*res)%k;
    if(b&1)ans = (ans + a)%k;
    return ans;
}

int main()
{
    int n;
    ll k;

    lell(k);
    le(n);

    loop(i,1,n+1)
    {
        cin>>a[i];
        dp[i][i]=a[i];
    }
  //  cout<<"1d\n";
    if(n<=8000){
    vi v;
    int flag=0;
    loop(i,1,n+1)
    {
        if(a[i]%k==0)
        {
            flag=1;
            v.pb(i);
        }
    }
    if(flag==1)
    {
        cout<<"Minimum interval length: 1\nFound intervals:\n";
        loop(i,0,v.size())
        {
            printf("[%d, %d]\n",v[i],v[i]);
        }
        return 0;
    }
    v.clear();
    int hv;
    loop(l,2,n+1)
    {
        int flag=0;
        loop(i,1,n-l+1+1)
        {

            dp[i][i+l-1]=mult(dp[i][i],dp[i+1][i+l-1],k);
            if(dp[i][i+l-1]%k==0)
            {
                flag=1;
                v.pb(i);
            }

        }
        if(flag==1)
        {
            cout<<"Minimum interval length: "<<l<<"\n";
                cout<<"Found intervals:\n";
            loop(i,0,v.size())
            {
                hv=v[i]+l-1;
                printf("[%d, %d]\n",v[i],hv);
            }
            return 0;
        }

    }
    cout<<"NONE\n";
    return 0;
    }


    cout<<"NONE\n";

    return 0;
}
