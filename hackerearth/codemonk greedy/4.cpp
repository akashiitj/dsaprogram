
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

pii a[100001];
pii b[100001];

int vis[100001];

int main()
{
    int m,n;
    int x,y;
    int gp;
    int pp;
    frmlty
    {   map<pii,int> mb;
        map<int,int> m1;
        gp=0;
        pp=0;
        le2(m,n);
        loop(i,0,m)
        {
            le2(x,y);
            a[i]=mp(x,y);
            vis[i]=0;
            //ma[a[i]]++;
        }

        loop(i,0,n)
        {
            le2(x,y);
            b[i]=mp(x,y);

            mb[b[i]]++;
            m1[b[i].first]++;
        }

        loop(i,0,m)
        {
            if(mb[a[i]]>0)
            {   vis[i]=1;
                pp++;
                gp++;
                mb[a[i]]--;
                m1[a[i].first]--;
            }
        }
        loop(i,0,m)
        {
            if(m1[a[i].first]>0&&vis[i]==0)
            {
                gp++;
                //mb[a[i]]--;
                m1[a[i].first]--;
            }
        }

        int gpe;
        int ppe;
        le2(gpe,ppe);

        if(pp>=ppe&&gp>=gpe)
            cout<<"Great\n";
        else if(gp>=gpe)
            cout<<"Good\n";
        else
            cout<<":(\n";

    }
    return 0;
}

