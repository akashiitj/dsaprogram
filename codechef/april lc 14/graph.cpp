
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

#define fast      ios_base::sync_with_stdio(false)
#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<LL>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair



#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define mod       1000000007

int fa[1000000]= {0};
int sa[1000000]= {0};

int main()
{
    fast;
    ll n,m;
    cin>>n>>m;
    ll x,c ,v;

    vector<pair<int,pair<int,int > > > e;
    loop(i,0,m)
    {
        //cin>>x>>c>>v;
        pair<int,pair<int,int > > x;
        cin>>x.second.first>>x.second.second>>x.first;
        e.push_back(x);

    }
    sort(e.begin(),e.end());

    loop(i,0,n)
    {
        fa[i]=0;
        sa[i]=0;
    }
    int c1=0,c2=0;
    int bv;

    loop(i,0,m)
    {
        int v1=e[i].second.first;
        int v2=e[i].second.second;
        if(fa[v1]==0&&sa[v1]==0)
        {
            fa[v1]=1;
            c1++;
            if(c1==n/2)
            {
                bv=1;
                break;

            }
        }
        if(fa[v2]==0&&sa[v2]==0)
        {
            sa[v2]=1;
            c2++;
            if(c2==n/2)
            {
                bv=2;
                break;

            }
        }
    }
   if(c1>=c2){
        loop(i,0,n)
        if(fa[i]==1)cout<<i<<" ";
        int left=(n/2)-c1;
        int i=0;
        loop(i,0,n)
        {
            if(left<=0)break;
            if(fa[i]==0)
            {
                cout<<i<<" ";
                left--;
            }

        }
    cout<<endl;}
    else{
            loop(i,0,n)
        if(sa[i]==1)cout<<i<<" ";
        int left=(n/2)-c2;
        int i=0;
        loop(i,0,n)
        {
            if(left<=0)break;
            if(sa[i]==0)
            {
                cout<<i<<" ";
                left--;
            }

        }
    cout<<endl;


    }


}
