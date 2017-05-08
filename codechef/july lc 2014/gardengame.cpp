#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

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

ll pf[100001];

ll mod1(ll x)
{
    return x%1000000007;
}

void update(int n)
{
    int  c=0;
    while(n%2==0)
    {
        n=n/2;
        c++;
    }
    if(c>0)  pf[2]=maX(pf[2],c);
    for(int i=3; i*i<=n; i=i+2)
    {
        c=0;
        while(n%i==0)
        {
            c++;
            n=n/i;
        }
        if(c>0) pf[i]=maX(pf[i],c);
    }
    if(n>2)
    {
        pf[n]=maX(pf[n],1);
    }
}
ll fast_mul(ll A,ll pow)
{
    ll C=1;


    while(pow>0)
    {
        if(pow&1)
        {
            C=C*A;
            if(C>mod)
                C=mod1(C);
            // cout<<C<<" "<<mod1(A)<<endl;
        }
        A=A*A;
        if(A>mod)A=mod1(A);
        pow>>=1;
    }
    return C;
}

int main()
{
    frmlty
    {
        int n,c,np;
        le(n);
        int a[n+1];
        int vis[n+1];
        loop(i,1,n+1)
        {
            pf[i]=0;
            vis[i]=0;
            le(a[i]);
        }
//        loop(i,0,n)
//        {
//            cout<<a[i]<<" ";
//        }
//        cout<<endl;

        loop(i,1,n+1)
        {
            c=1;
            if(vis[i]==0)
            {
                vis[i]=1;
                np=i;

                while(a[np]!=i)//finding length of cycle
                {
                    vis[np]=1;
                    np=a[np];
                    c++;
                }
                vis[np]=1;

                update(c);//update lcm
            }
            //cout<<c<<" "<<i<<endl;
        }
        ll ans=1;
        loop(i,1,n+1)
        {
            ans=ans*fast_mul(i,pf[i]);

            if (ans>=1000000007)
            {
                ans=mod1(ans);
            }
        }
        printf("%lld\n",ans);
        //   cout<<ans<<endl;


    }
    return 0;
}

