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

int st[26][1000000];
int lazy[26][1000000];

void build(int tn,int sti,int si,int ei)
{
    if(si==ei)
    {
        if((s[si-1]-'a')==tn)st[tn][sti]=1;
        lazy[tn][sti]=-1;
        return;
    }
    lazy[tn][sti]=-1;
    int mid=(si+ei)/2;
    build(tn,2*sti,si,mid);
    build(tn,(2*sti)+1,mid+1,ei);
    st[tn][sti]=st[tn][2*sti]+st[tn][(2*sti)+1];
}

int cnt(int tn,int i,int j,int sti,int si,int ei)
{
    if(j<si||i>ei)return 0;
    if(lazy[tn][sti]!=-1)
    {
        st[tn][sti]=lazy[tn][sti]*(ei-si+1);
        if(si!=ei)
        {
            lazy[tn][sti*2]=lazy[tn][sti];
            lazy[tn][sti*2+1]=lazy[tn][sti];
        }
        lazy[tn][sti]=-1;
    }
    if(i<=si&&j>=ei)return st[tn][sti];

    int mid=(si+ei)/2;
    return cnt(tn,i,j,2*sti,si,mid)+cnt(tn,i,j,(2*sti)+1,mid+1,ei);
}

void update(int tn,int i,int j,int dx,int sti,int si,int ei)//dx is always 1 so no need to include dx
{

    if(lazy[tn][sti]!=-1)
    {
        st[tn][sti]=lazy[tn][sti]*(ei-si+1);
        if(si!=ei)
        {
            lazy[tn][sti*2]=lazy[tn][sti];
            lazy[tn][sti*2+1]=lazy[tn][sti];
        }
        lazy[tn][sti]=-1;
    }
    if(j<si||i>ei)return;
    if(si>=i&&ei<=j)
    {
        st[tn][sti]=dx*(ei-si+1);
        lazy[tn][sti*2]=dx;
        lazy[tn][sti*2+1]=dx;
        return;
    }
    int mid=(si+ei)/2;
    update(tn,i,j,dx,2*sti,si,mid);
    update(tn,i,j,dx,(2*sti)+1,mid+1,ei);

    st[tn][sti]=st[tn][2*sti]+st[tn][(2*sti)+1];

}


int main()
{
    int n,q,l,r,hv;
    le2(n,q);
    cin>>s;
    int c,tl;

    loop(i,0,26)
    build(i,1,1,n);




    int tsi,tei;
    loop(i,0,q)
    {
        le2(l,r);
        le(hv);
        tl=r-l+1;
        tsi=l;



        if(hv==1)
        {
            loop(j,0,26)
            {
                c=cnt(j,l,r,1,1,n);
                if(c>0)
                {
                    update(j,l,r,0,1,1,n);
                    update(j,tsi,tsi+c-1,1,1,1,n);
                    tsi=tsi+c;
                }
            }
        }
        else
        {
            for(int j=25; j>=0; j--)
            {
                c=cnt(j,l,r,1,1,n);
                if(c>0)
                {
                    update(j,l,r,0,1,1,n);
                    update(j,tsi,tsi+c-1,1,1,1,n);
                    tsi=tsi+c;
                }
            }

        }
    }

    loop(i,0,n)
    {
        loop(j,0,26)
        {
            c=cnt(j,i+1,i+1,1,1,n);
            if(c==1)s[i]=j+'a';
        }
    }

    cout<<s<<"\n";
    return 0;
}

