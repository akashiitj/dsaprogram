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
        st1[sti]=a[si];
        return;
    }
    ll mid=(si+ei)/2;
    build(2*sti,si,mid);
    build((2*sti)+1,mid+1,ei);
    st[sti]=st[2*sti]+st[(2*sti)+1];//for sum query
    st1[sti]=min(st1[2*sti],st1[(2*sti)+1]);//for min query

}
void update(ll i,ll dx,ll sti,ll si,ll ei)//sti means index in seg tree representing si to ei interval,si starting index of segment of original array
{
    if(i<si||i>ei)return;
    st[sti]=dx+st[sti];

    if(si!=ei)//condition for base case
    {
        ll mid=(si+ei)/2;
        update(i,dx,sti*2,si,mid);
        update(i,dx,(sti*2)+1,mid+1,ei);

    }

}

void updatemin(ll i,ll newvalue,ll sti,ll si,ll ei)//sti means index in seg tree representing si to ei interval,si starting index of segment of original array
{
    if(i<si||i>ei)return;
   // if(st1[sti]>newvalue)st1[sti]=newvalue;//if that index lie in between si to ei then update st node representing that interval .its wrong
    if(si==ei)
        st1[sti]=newvalue;
    if(si!=ei)//condition for base case
    {
        ll mid=(si+ei)/2;
        updatemin(i,newvalue,sti*2,si,mid);
        updatemin(i,newvalue,(sti*2)+1,mid+1,ei);

        st1[sti]=min(st1[2*sti],st1[(2*sti)+1]);
    }


}

void updatemininrange(ll i,ll j,ll dx,ll sti,ll si,ll ei)//sti means index in seg tree representing si to ei interval,si starting index of segment of original array
{
    if(j<si||i>ei)return;
   // if(st1[sti]>newvalue)st1[sti]=newvalue;//if that index lie in between si to ei then update st node representing that interval .its wrong
    if(si==ei)
        st1[sti]+=dx;
    if(si!=ei)//condition for base case
    {
        ll mid=(si+ei)/2;
        updatemininrange(i,j,dx,sti*2,si,mid);
        updatemininrange(i,j,dx,(sti*2)+1,mid+1,ei);

        st1[sti]=min(st1[2*sti],st1[(2*sti)+1]);
    }


}

ll sum(ll i,ll j,ll sti,ll si,ll ei)
{
    if(i<=si&&j>=ei)//this imply whole part from si to ei must be going to add up for required sum
        return st[sti];
    if((si>j)||(i>ei))//this is not going to be included
        return 0;
    ll mid =(si+ei)/2;
    return sum(i,j,2*sti,si,mid)+sum(i,j,(2*sti)+1,mid+1,ei);//search for sum in left and rigth subtree
}
ll minq(ll i,ll j,ll sti,ll si,ll ei)
{
    if(i<=si&&j>=ei)//this imply whole part from si to ei must be going to add up for required sum
        return st1[sti];
    if((si>j)||(i>ei))//this is not going to be included
        return 1000000;
    ll mid =(si+ei)/2;
    return min(minq(i,j,2*sti,si,mid),minq(i,j,(2*sti)+1,mid+1,ei));
}
void p(ll ml)
{
    loop(i,1,15)
    cout<<st[i]<<" ";.
    cout<<endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    loop(i,1,n+1)
    cin>>a[i];
    build(1,1,n);
    cout<<  minq(1,5,1,1,5)<<endl;
    updatemininrange(1,2,5,1,1,5);//change a[i] also
//    p(n);
    cout<<  minq(1,5,1,1,5);
    return 0;
}
