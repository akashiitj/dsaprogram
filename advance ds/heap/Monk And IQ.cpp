
//author akashiitj
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

priority_queue<pii,vector<pii >,greater<pii > > q;//min priority q
int crs[100001][3]={};
int main()
{
    int c,p,n;
    cin>>c>>p>>n;
    int ans[p];
    int iq_student[n],iq_monks[p];
    loop(i,0,n)
    {
        cin>>iq_student[i];
        crs[i][0]=iq_student[i];
        crs[i][1]=0;
        crs[i][2]=1;
        q.push(make_pair(((crs[i][0]+crs[i][1])*crs[i][2]),i));
    }
    loop(i,n,c)
    {

        crs[i][0]=0;
        crs[i][1]=0;
        crs[i][2]=0;
        q.push(make_pair(((crs[i][0]+crs[i][1])*crs[i][2]),i));
    }
    loop(i,0,p)
        cin>>iq_monks[i];

    loop(i,0,p)
    {
        pii x=q.top();
        q.pop();
        ans[i]=x.second;
        crs[x.second][1]=crs[x.second][0];
        crs[x.second][0]=iq_monks[i];
        crs[x.second][2]++;
        q.push(make_pair(((crs[x.second][0]+crs[x.second][1])*crs[x.second][2]),x.second));

    }

    loop(i,0,p)
      cout<<ans[i]+1<<" ";

    cout<<"\n";

    return 0;

}
