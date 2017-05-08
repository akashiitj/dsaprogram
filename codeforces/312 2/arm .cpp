
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

int vis[100001]={};
int times[100001]={};
int cost[100001]={};

int main()
{
    int n;
    le(n);
    int x;
    int c=0,d=0;
    loop(i,1,n+1)
    {
        le(x);
        c=0;
        d=0;
        while(x>=1)
        {   c=d;
            for(int j=x;j<=100000;j=j*2)
            {
                if(vis[j]!=i)
                {
                    vis[j]=i;
                    times[j]++;
                    cost[j]+=c;
                }
                c++;
            }
            x=x/2;
            d++;

        }
    }
    int ans=INT_MAX;
    loop(i,1,100001)
    {
        if(times[i]==n)
            ans=miN(ans,cost[i]);

    }
    cout<<ans<<"\n";
    return 0;
}


