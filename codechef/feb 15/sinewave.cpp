#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

#define fast      ios_base::sync_with_stdio(false)
#define frmlty    int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<LL>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair

ll fast_mul(ll A,ll pow)
{
    ll C=1;


    while(pow>0)
    {
        if(pow&1)
        {
            C=A*C;


        }
        A=A*A;
        pow>>=1;
    }
    return C;
}

#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define mod       1000000007

ll a[50];//power of 2 table
ll cs[50];//cumulative sum table of power of 2

int main()
{
    fast;
    a[0]=1;
    cs[0]=0;
    loop(i,1,51)
    {
        a[i]=a[i-1]*2;
        cs[i]=cs[i-1]+a[i];
    }
    ll s,c,k;
    ll anss,ansc,ans;
    frmlty
    {
        cin>>s>>c>>k;
        ansc=0;
        if(s==0)
        {
            if(k==1)cout<<cs[c]<<endl;
            if(k>1)cout<<"0"<<endl;
            continue;
        }
        if(k>s)
        {
            cout<<"0"<<endl;
            continue;
        }
        if(k<=s)
        {
            anss=3+(fast_mul(2,s-k)-1)*2;
            if(s-k+1<=c)
            {
                ansc=a[s-k+1];
                if(k==1)
                    ansc=ansc+cs[c]-cs[s-k+1];
            }
            ans=ansc+anss;
            cout<<ans<<endl;
        }
    }
    return 0;
}
