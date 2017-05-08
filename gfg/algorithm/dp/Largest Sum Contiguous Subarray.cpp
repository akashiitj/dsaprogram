
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

int a[10];

int dpk[10];
int dp[10];
int n;


void kadane()//it doesnt work for all -ive number
{
    int maxupto=0;
    int ans=0;
    loop(i,1,n+1)
    {
        maxupto=maxupto+a[i];
        if(maxupto<0)maxupto=0;
        ans=maX(ans,maxupto);
    }
    cout<<ans;
}

void f()
{
    int maxupto=a[1];//you are making mistke here
    int ans=a[1];
    loop(i,2,n+1)
    {
        maxupto=maX(maxupto+a[i],a[i]);
        ans=maX(ans,maxupto);
    }
    cout<<ans;
}



int main()
{
    le(n);
    loop(i,1,n+1)
    le(a[i]);
    kadane();
    cout<<"\n";
    f();
    cout<<"\n";

    return 0;
}

