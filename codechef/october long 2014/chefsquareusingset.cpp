
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

#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define le2d(x,y) scanf("%lf%lf",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);


int main()
{
    int n;
    double x,y;
    le(n);
    if(n<2)
    {

        cout<<4-n<<"\n";
        return 0;
    }
    set<pair<double,double> > v;
    loop(i,0,n)
    {
        le2d(x,y);
        v.insert(mp(x,y));
    }

    int ans=2,fans=2;
    double x1,y1,x2,y2,xc,yc,x3,y3,x4,y4;
    for(set<pair<double,double> > ::iterator i=v.begin(); i!=v.end(); i++)
    {
        x1=i->first;
        y1=i->second;
        set<pair<double,double> > ::iterator j=i;
        if(i!=v.end())//j=i+1 is not allowed so we have to do this
        {


            for(++j; j!=v.end(); j++)
            {
                ans=2;
                x2=j->first;
                y2=j->second;
                xc=(x1+x2)/2.0;
                yc=(y1+y2)/2.0;
                x3=xc-(y1-yc);
                y3=yc+(x1-xc);

                x4=xc+(y1-yc);
                y4=yc-(x1-xc);

                // cout<<x3<<" "<<y3<<"   "<<x4<<" "<<y4<<"\n";

                if(v.find(mp(x3,y3))!=v.end())
                    ans--;

                if(v.find(mp(x4,y4))!=v.end())
                    ans--;

                fans=min(ans,fans);

                if(fans==0)break;

            }
        }
        if(fans==0)break;
    }
    cout<<fans<<"\n";
    return 0;
}

