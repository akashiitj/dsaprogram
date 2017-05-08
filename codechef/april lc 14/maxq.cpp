#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;


ll a[1000005];

ll st1[1000005];//for max1 query

ll getMid(ll s, ll e) {  return s + (e -s)/2;  }

ll max1(ll x, ll y) { return (x >= y)? x: y; }
ll min1(ll x, ll y) { return (x <= y)? x: y; }

void build(ll i,ll si,ll ei)
{
    if(si==ei)
    {
       // st[i]=a[si];
        st1[i]=a[si];
        return;
    }
    ll mid=getMid(si,ei);
    build((2*i)+1,si,mid);
    build((2*i)+2,mid+1,ei);

    st1[i]=max1(st1[(2*i)+1],st1[(2*i)+2]);//for max1 query

}

ll max1q(ll i,ll j,ll sti,ll si,ll ei)//find max1 between i and j
{
    if(i<=si&&j>=ei)//this imply whole part from si to ei must be going to add up for required sum
        return st1[sti];
    if((si>j)||(i>ei))//this is not going to be included
        return -1;
    ll mid =getMid(si,ei);
    return max1(max1q(i,j,(2*sti)+1,si,mid),max1q(i,j,(2*sti)+2,mid+1,ei));
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    loop(i,0,n)
    cin>>a[i];
    build(0,0,n-1);
    ll m,x,y;
    cin>>m>>x>>y;
    ll ans=0;

    ans=ans+max1q(min1(x,y),max1(x,y),0,0,n-1);
    //cout<<ans<<endl;
    loop(i,1,m)
    {   //cout<<ans<<" "<<x<<" "<<y<<endl;
        x=(x+7)%(n-1);
        y=(y+11)%(n);


      //  cout<<min1(x,y)<<" "<<max1(x,y)<<" ";
        ans=ans+max1q(min1(x,y),max1(x,y),0,0,n-1);
       // cout<<ans<<" "<<endl;
    }
    cout<<ans<<endl;

    return 0;
}

