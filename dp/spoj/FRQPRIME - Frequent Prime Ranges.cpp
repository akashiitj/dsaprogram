
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

int a[100001];
int cs[100001];
void seive()
{
    a[1]=1;
    for(int i=2; i*i<=100000; i++)
    {
        if(a[i]==0)
        {
            for(int j=i*i; j<=100000; j=j+i)
                a[j]=1;
        }
    }
    loop(i,1,100001)
    cs[i]=cs[i-1]+(a[i]==0);

    //cout<<cs[100000]<<"\n";
}

int main()
{
    int n,k;
    seive();
    ll ans=0;
    int li;
    frmlty
    {
        ans=0;
        le2(n,k);
        li=1;
        int i1=2;
        while(i1<=n&&cs[i1]-cs[li]<k)//finding first k freq subarray
            i1++;
        if(i1<=n) ans=ans+li*1LL;
        loop(i,i1+1,n+1)
        {   //li and its prev index form required subarry with i index
            while(li<i&&cs[i]-cs[li]>=k)//first you have done li<=i so li is becoming i+1 in corner case like k=0;
                li++;
            ans=ans+(1LL*li-1);
        }
        cout<<ans<<"\n";
    }
    return 0;
}

