#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

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

ll a[100005];
ll st[1000005];//for sum query
ll st1[1000005];//for min query

int n;

void build(ll sti,ll si,ll ei)//sti node of segment tree hold sum from start index  to end index of original array
{
    if(si==ei)
    {
        st[sti]=si;
        st1[sti]=a[si];
        return;
    }
    ll mid=(si+ei)/2;
    build(2*sti,si,mid);
    build((2*sti)+1,mid+1,ei);
   // st[sti]=st[2*sti]+st[(2*sti)+1];//for sum query
    if(st1[2*sti]<st1[(2*sti)+1])
        st[sti]=st[2*sti];
    else st[sti]=st[(2*sti)+1];
    st1[sti]=min(st1[2*sti],st1[(2*sti)+1]);//for min query

}



ll minq(ll i,ll j,ll sti,ll si,ll ei)
{
    if(i<=si&&j>=ei)//this imply whole part from si to ei must be going to add up for required sum
        return st[sti];
    if((si>j)||(i>ei))//this is not going to be included
        return INT_MAX;
    ll mid =(si+ei)/2;
    return min(minq(i,j,2*sti,si,mid),minq(i,j,(2*sti)+1,mid+1,ei));
}

ll f(int i,int j)
{
    if(i>j)
        return 0;
    int mi=minq(i,j,1,1,n);
    ll pa=a[mi]*1LL*(j-i+1);
    ll a1=f(i,mi-1);
    ll a2=f(mi+1,j);
    return maX(pa,maX(a1,a2));
}

int main()
{

    while(true)
    {


        le(n);
        if(n==0)
            break;
        loop(i,1,n+1)
        {
            lell(a[i]);
        }
        build(1,1,n);
        cout<<f(1,n)<<"\n";
    }


    return 0;
}


/*
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

ll h[100001];
int nsr[100001];
int nsl[100001];
vll v;
ll fa=0;

int main()
{
    int n;
    while(true)
    {
        fa=0;
        memset(nsr,0,sizeof(nsr));
        memset(nsl,0,sizeof(nsl));
        le(n);
        if(n==0)
            break;
        loop(i,1,n+1)
        {
            lell(h[i]);
        }
        v.clear();
        v.pb(0);

        loop(i,1,n+1)
        {
            while(v.back()!=0&&h[v.back()]>h[i])
            {
                nsr[v.back()]=i;
                v.pop_back();
            }
            v.pb(i);

        }
        v.clear();
        v.pb(0);

        reverse(h+1,h+1+n);
        loop(i,1,n+1)
        {
            while(v.back()!=0&&h[v.back()]>h[i])
            {
                nsl[v.back()]=i;
                v.pop_back();
            }
            v.pb(i);


        }

        reverse(nsl+1,nsl+n+1);

        loop(i,1,n+1)
        if(nsr[i]==0)nsr[i]=n+1;


        loop(i,1,n+1)
        {

            if(nsl[i]!=0)nsl[i]=n+1-nsl[i];

        }
        reverse(h+1,h+1+n);
        loop(i,1,n+1)
        fa=maX(fa,(nsr[i]-nsl[i]-1)*1LL*h[i]);

        cout<<fa<<"\n";









    }
    return 0;
}

*/
