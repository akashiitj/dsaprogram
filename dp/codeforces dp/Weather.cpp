

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

#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf(" %I64d",&x);
#define le2ll(x,y) scanf(" %I64d%I64d",&x,&y);

#define F first;
#define S second;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

int fp[100001]= {};
int bn[100001]= {};
int main()
{   freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int n;
    le(n);
    int a[n];
    loop(i,0,n)
    {
        le(a[i]);
    }

    if(a[0]>=0)fp[0]=1;
    loop(i,1,n)
    if(a[i]>=0)fp[i]+=fp[i-1]+1;
    else fp[i]=fp[i-1];

    if(a[n-1]<=0)bn[n-1]=1;
    for(int i=n-2; i>=0; i--)
        if(a[i]<=0) bn[i]+=bn[i+1]+1;
     else bn[i]+=bn[i+1];
    int ans=INT_MAX;
    loop(i,0,n-1)
    {
        ans=miN(ans,fp[i]+bn[i+1]);
    }
    cout<<ans<<"\n";
    return 0;
}


