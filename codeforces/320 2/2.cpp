#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

#define fast      ios_base::sync_with_stdio(false);
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
#define lell(x) scanf(" %I64d",&x);
#define le2ll(x,y) scanf(" %I64d%I64d",&x,&y);
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
using namespace std;
int mark[1000],ans[1000];
vector< pair<int,pii> > v;
int main()
{
    int n;
    le(n);
    for(int i=2;i<=2*n;i++)
    {
        for(int j=1;j<i;j++)
        {
            int temp;
            le(temp);
            v.pb(mp(temp,mp(i,j)));
        }
    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--)
    {
        int p = v[i].se.fe;
        int q = v[i].se.se;
        if(!mark[p]&&!mark[q])
        {
            ans[p]=q;
            ans[q]=p;
            mark[p]=1;mark[q]=1;
        }
    }
    for(int i=1;i<=2*n;i++)
    {
        printf("%d ",ans[i]);

    }
    cout<<endl;
    return 0;
}
