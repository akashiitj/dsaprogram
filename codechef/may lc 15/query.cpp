#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;

const int mod = 1000000007;

int N;

ll arr[10000001];
ll st1[10000005];//for min query

void build(ll i,ll si,ll ei)//i node of segment tree hold sum from start index  to end index of original array
{
    if(si==ei)
    {

        st1[i]=arr[si];
        return;
    }
    ll mid=(si+ei)/2;
    build(2*i,si,mid);
    build((2*i)+1,mid+1,ei);

    st1[i]=min(st1[2*i],st1[(2*i)+1]);//for min query

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
ll pow12[10000001];
int main()
{

    int t1=1000000000;
    ll x=t1*t1;
    cout<<x<<endl;
    std::ios_base::sync_with_stdio(false);
    ll K,Q;
    cin>>N>>K>>Q;
    ll a,b,c,d,e,f,r,s,t,m;
    ll  L1, La, Lc, Lm, D1, Da, Dc, Dm;
   // scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&r,&s,&t,&m,&arr[1],&L1,&La,&Lc,&Lm,&D1,&Da,&Dc,&Dm);
   scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &a,&b,&c,&d,&e,&f,&r,&s,&t,&m,&arr[0], &L1,&La,&Lc,&Lm,&D1,&Da,&Dc,&Dm);
 //  cin>>a>>b>>c>>d>>e>>f>>r>>s>>t>>m>>arr[1];



//     scanf("%d %d %d %d %d %d %d %d ", &L1,&La,&Lc,&Lm,&D1,&Da,&Dc,&Dm);
   // cin>> L1>> La>> Lc>> Lm>> D1>> Da>> Dc>> Dm;

    pow12[1]=t;

    loop(x,2,N+1)
    {
        pow12[x]=pow12[x-1]*t;
        if(pow12[x]>=s)pow12[x]=pow12[x]%s;
    }

    loop(x,2,N+1)
    {
        if(pow12[x]  <= r)        // Here t^x signifies "t to the power of x"
            arr[x] = (a*(arr[x-1]*arr[x-1]) + b*arr[x-1] + c) % m;
        else
            arr[x] = (d*(arr[x-1]*arr[x-1]) + e*arr[x-1] + f) % m;
    }
    loop(i,1,N+1)
    cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}
