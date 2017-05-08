//given a array or set you hane to tell number of subset whose sum is dividible by k given in each query
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

ll dp[2][100];//dp[pre][x] tell us number of subset whsose element sum modulus k is x ans our ans is dp[pre][0]
ll ht[100];//h[i] count number of element having no%k=i
ll a[100001];//store element of array

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

    ll invx,x;
    ifact[1]=1;
    ifact[100000]=pow1(fact[100000],mod-2);

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

    int n,q;
    init();//intialization for factorial calculation

    ll x,k;
    frmlty
    {
        le2(n,q);//n is number of element and q is query
        loop(i,0,n)
        lell(a[i+1]);

        ll number[100+1];//number[i] important. it count number of subset having sum i for each ht[].so that if we have to find dp[cur][j] +=dp[pre][j-i]*number[i]
        ll hv,hv2;

        loop(i1,0,q)
        {
            lell(k);//tell how many subset are divisible by k

            loop(i,0,k)
            ht[i]=0;

            loop(i,0,n)
            {
                hv2=a[i+1]%k;
                while(hv2<0)hv2+=k;
                ht[hv2]++;
            }

            dp[0][0]=1;//empty set
            int pre=0;
            int cur=1;
            loop(i,1,100)//all other are 0
            dp[pre][i]=0;

            ll hv3,sum1;
            loop(i,0,k)
            {

                if(ht[i]!=0)
                {
                    loop(j,0,k)
                    number[j]=0;
                    sum1=0;
                    loop(j,1,ht[i]+1)//calculating number array
                    {
                        sum1=sum1+i;
                        if(sum1>=k)sum1=sum1%k;
                        number[sum1]+=ncr(ht[i],j);//note it is += first you forgot it
                        if(number[sum1]>=mod)number[sum1]=number[sum1]%mod;
                    }

                    loop(j,0,k)
                    {
                        dp[cur][j]=dp[pre][j];
                        loop(l,0,k)
                        {
                            ll x1=j-l;
                            while(x1<0)x1=x1+k;
                            dp[cur][j]+=(dp[pre][x1]*number[l]);//in each dp[pre][x1] set we can add number of set having sum lto obtain set having j sum
                            if(dp[cur][j]>=mod)dp[cur][j]=dp[cur][j]%mod;
                        }
                    }
                    swap(pre,cur);
                }
            }
            cout<<dp[pre][0]<<endl;
        }
    }
    return 0;
}





