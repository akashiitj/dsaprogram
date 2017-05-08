
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000009;

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
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

ll dp[2][100];
ll ht[100];
ll a[100001];

ll fact[100001];
ll ifact[100001];

ll pow1(ll a, ll b)
{
    ll x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x;
}

void init()
{
    fact[0]=1;
    loop(i,1,100001)
    {
        fact[i]=fact[i-1]*i;
        if(fact[i]>=mod)fact[i]=fact[i]%mod;
    }
    //cout<<" c1"<<"\n";
    ll invx,x;
    ifact[1]=1;
    ifact[100000]=pow1(fact[100000],mod-2);
    //cout<<" c2"<<"\n";
    for(ll i=100000-1; i>=2; i--)
    {

        ifact[i]=ifact[i+1]*(i+1);
        if(ifact[i]>=mod)ifact[i]=ifact[i]%mod;
    }
}

ll ncr(ll n,ll r)
{
    if(r==0 || r==n)return 1;
    ll x=(fact[n]*ifact[r])%mod;
    x=(x*ifact[n-r])%mod;
    return x;
}



int main()
{
    //cout<<" c1"<<"\n";
    int n,q;
    init();

    ll x,k;
    frmlty
    {
        le2(n,q);
        loop(i,0,n)
        {
            lell(a[i+1]);

        }
        ll number[100+1];
        ll hv,hv2;
        cout<<"c1\n";
        loop(i1,0,q)
        {
            lell(k);

            loop(i,0,k)
            ht[i]=0;

            loop(i,0,n)
            {
                hv2=a[i+1]%k;
                while(hv2<0)hv2+=k;
                ht[hv2]++;
            }

            loop(i,0,k)
            cout<<ht[i]<<" ";
            cout<<"\n";

            dp[0][0]=1;
            int pre=0;
            int cur=1;
            loop(i,1,100)
            dp[pre][i]=0;

            ll hv3,sum1;
            loop(i,0,k)
            {
                loop(j,0,k)
                number[j]=0;
                if(ht[i]!=0)
                {
                    number[0]=0;
                    sum1=0;
                    loop(j,1,ht[i]+1)
                    {
                        sum1=sum1+i;
                        if(sum1>=k)sum1=sum1%k;
                        number[sum1]+=ncr(ht[i],j);
                        if(number[sum1]>=mod)number[sum1]=number[sum1]%mod;
                    }
                    cout<<"nimber\n";
                    loop(j,0,k)
                    cout<<number[j]<<" ";
                    cout<<endl;
                    loop(i111,0,k)
                    dp[cur][i]=0;

                    loop(j,0,k)
                    {    dp[cur][j]=dp[pre][j];
                        loop(l,0,k)
                        {

                            ll x1=j-l;
                            while(x1<0)x1=x1+k;
                            cout<<x1<<" x1 "<<dp[pre][x1]<<" "<<j<<" j "<<dp[pre][j]<<" \n";
                            dp[cur][j]+=(dp[pre][x1]*number[l]);
                            if(dp[cur][j]>=mod)dp[cur][j]=dp[cur][j]%mod;

                            cout<<dp[cur][j]<<endl;

                        }
                    }
                    loop(i111,0,k)
                    cout<<dp[cur][i]<<" ";
                    cout<<endl;
                }
                swap(pre,cur);
            }
            cout<<dp[pre][0]<<endl;

        }
    }
    return 0;
}




