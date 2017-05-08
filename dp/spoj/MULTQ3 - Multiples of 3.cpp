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

#define F first
#define S second

string s;

int st[3][2000000];
int lazy[2000000];



void build(int sti,int si,int ei)
{
    if(si==ei)
    {
        st[0][sti]=1;
        lazy[sti]=0;
        return;
    }
    lazy[sti]=0;
    int mid=(si+ei)/2;
    build(2*sti,si,mid);
    build((2*sti)+1,mid+1,ei);
    st[0][sti]=st[0][2*sti]+st[0][(2*sti)+1];
}

int cnt(int i,int j,int sti,int si,int ei)
{
    if(j<si||i>ei)return 0;
    if(lazy[sti]!=0)
    {
        //st[sti]=lazy[sti]*(ei-si+1);
        int val = lazy[sti];
   		int temp = st[0][sti];
        st[0][sti] = st[(0+2*val)%3][sti];
        st[(0+2*val)%3][sti] = st[(0+4*val)%3][sti];
        st[(0+4*val)%3][sti] = temp;

        if(si!=ei)
        {
            lazy[sti*2]=(lazy[sti]+lazy[sti*2])%3;
            lazy[sti*2+1]=(lazy[sti]+lazy[sti*2+1])%3;;
        }
        lazy[sti]=0;
    }
    if(i<=si&&j>=ei)return st[0][sti];

    int mid=(si+ei)/2;
    return cnt(i,j,2*sti,si,mid)+cnt(i,j,(2*sti)+1,mid+1,ei);
}

void update(int i,int j,int dx,int sti,int si,int ei)//dx is always 1 so no need to include dx
{

    if(lazy[sti]!=0)
    {
        int val = lazy[sti];
   		int temp = st[0][sti];
        st[0][sti] = st[(0+2*val)%3][sti];
        st[(0+2*val)%3][sti] = st[(0+4*val)%3][sti];
        st[(0+4*val)%3][sti] = temp;



        if(si!=ei)
        {
            lazy[sti*2]=(lazy[sti]+lazy[sti*2])%3;
            lazy[sti*2+1]=(lazy[sti]+lazy[sti*2+1])%3;
        }
        lazy[sti]=0;
    }
    if(j<si||i>ei)return;
    if(si>=i&&ei<=j)
    {
        int val = dx;
   		int temp = st[0][sti];
        st[0][sti] = st[(0+2*val)%3][sti];
        st[(0+2*val)%3][sti] = st[(0+4*val)%3][sti];
        st[(0+4*val)%3][sti] = temp;


        //swap(st[0][sti],st[1][sti]);
        lazy[sti*2]=(dx+lazy[sti*2])%3;
        lazy[sti*2+1]=(dx+lazy[sti*2+1])%3;
        return;
    }
    int mid=(si+ei)/2;
    update(i,j,dx,2*sti,si,mid);
    update(i,j,dx,(2*sti)+1,mid+1,ei);

    st[0][sti]=st[0][2*sti]+st[0][(2*sti)+1];
    st[1][sti]=st[1][2*sti]+st[1][(2*sti)+1];
     st[2][sti]=st[2][2*sti]+st[2][(2*sti)+1];


}
int main()
{

    int n,m;
    le2(n,m);
    build(1,1,n);
    int x;
    int c=1;
    int l,r;
    loop(i,0,m)
    {
        le(x);
        if(x==0)
        {
            le2(l,r);
            l++;
            r++;
            update(l,r,1,1,1,n);
            c++;
        }
        if(x==1)
        {
            le2(l,r);
            l++;
            r++;
            printf("%d\n",cnt(l,r,1,1,n));
        }
    }
    return 0;
}


