
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

#define F first;
#define S second;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

vector<pair<pii ,int> > v;
vector<pii> ans;
int book[1001]= {};
int main()
{
    int n;
    le(n);
    int m,pn,c;
    loop(i,0,n)
    {
        le2(pn,c);
        v.pb(mp(mp(c,pn),i+1));
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());



    int k,hv;
    le(k);
    int an=0;
    pii a[k];
    loop(i,0,k)
    {
        le(hv);
        a[i].first=hv;
        a[i].second=i+1;
    }
    sort(a,a+k);

    loop(i,0,n)
    {
        loop(j,0,k)
        {
            if(book[j]==0&&a[j].first>=v[i].first.second)
            {

                ans.pb(mp(v[i].second,a[j].second));
                an=an+v[i].first.first;
                book[j]=1;
                break;
            }
        }
    }
    cout<<ans.size()<<" "<<an<<"\n";
    sort(ans.begin(),ans.end());
    loop(i,0,ans.size())
    cout<<ans[i].first<<" "<<ans[i].second<<"\n";

    return 0;
}


