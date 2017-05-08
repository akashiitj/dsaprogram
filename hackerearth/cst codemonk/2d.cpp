
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

vector<vector<int> > e;//vector of  edges    weight ,v1,v2
vector<vector<int> > fe;//edges in MST
int vn;
int en;

int comp[5001];

int findcomp(int cv)
{
    int i=cv;
    while(cv!=comp[cv])cv=comp[cv];

    while(i!=cv)//path compressor
    {
        int j=comp[i];
        comp[i]=cv;
        i=j;
    }
    return cv;
}

void union1(int v1,int v2)
{
    v1=findcomp( v1);
    v2=findcomp( v2);
    comp[v1]=v2;
}

void kruskal()
{
    sort(e.begin(),e.end());
    //reverse(e.begin(),e.end());
    int c=0;
    int i=en-1;
    while(c!=vn-1)
    {
        // cout<<findcomp(e[i][1])<<" fc "<<findcomp(e[i][1])<<endl
        if(findcomp(e[i][1])!=findcomp(e[i][2]))
        {
            union1(e[i][1],e[i][2]);
            fe.push_back(e[i]);
            c++;
        }
        i--;
    }
}

int main()
{
    int w,v1,v2;
    frmlty
    {
        cin>>vn>>en;

        loop(i,0,vn)
        {
            comp[i]=i;
        }
        e.clear();
        fe.clear();
        loop(i,0,en)
        {
            cin>>w>>v1>>v2;
            v1--;
            v2--;
            e.pb({w,v1,v2});
        }

        kruskal();
        cout<<"1\n";
        int ans=0;
        loop(i,0,vn-1)
        ans+=fe[i][0];

        cout<<ans<<"\n";
    }
    return 0;
}
