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


ll a[1000005];
ll st[1000005];//for sum query
ll st1[1000005];//for min query

void build(ll sti,ll si,ll ei)//sti node of segment tree hold sum from start index  to end index of original array
{
    if(si==ei)
    {
        st[sti]=a[si];
        st1[sti]=1;
        return;
    }
    ll mid=(si+ei)/2;
    build(2*sti,si,mid);
    build((2*sti)+1,mid+1,ei);
    if(st[2*sti]>st[(2*sti)+1])
        st1[sti]=st1[2*sti];
    else if(st[2*sti]<st[(2*sti)+1])
        st1[sti]=st1[2*sti+1];
    else
        st1[sti]=st1[2*sti+1]+st1[2*sti];


    st[sti]=maX(st[2*sti],st[(2*sti)+1]);


}

pii sum(ll i,ll j,ll sti,ll si,ll ei)//it is pair of max element and its frequency
{
    if(i<=si&&j>=ei)//this imply whole part from si to ei must be going to add up for required sum
        return mp(st[sti],st1[sti]);
    if((si>j)||(i>ei))//this is not going to be included
        return mp(0,0);

    ll mid =(si+ei)/2;
    pii l=sum(i,j,2*sti,si,mid);
    pii r=sum(i,j,(2*sti)+1,mid+1,ei);

    int ans=0;
    if(l.first>r.first)ans=l.second;
    else if(l.first<r.first)ans=r.second;
    else  ans=l.second+r.second;

    return mp(max(l.first,r.first),ans);
}



int main()
{
    int n,m;
    le2(n,m);

    loop(i,1,n+1)
    le(a[i]);

    build(1,1,n);

    int l,r;
    loop(i,0,m)
    {
        le2(l,r);
        printf("%d\n",sum(l,r,1,1,n).second);
    }
    return 0;
}
