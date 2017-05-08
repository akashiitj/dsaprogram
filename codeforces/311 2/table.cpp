
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

int ht[100001][201];
int cost[201];
int l[100001];
int main()
{
    int n;
    le(n);
    int x;
    loop(i,1,n+1)
    {
        le(l[i]);
        ht[l[i]][0]++;
    }

    loop(i,1,n+1)
    {
        le(x);
        ht[l[i]][x]++;
        cost[x]++;
    }
    int total=n;
    int rmv;
    int fa=INT_MAX;
    int pa=0;
    int ca=0;
    for(int i=100001; i>=1; i--)
    {
        if(ht[i][0]==0)continue;

        rmv=total-2*ht[i][0];
        rmv++;

        pa=ca;
        loop(j,1,201)
        {


            cost[j]=cost[j]-ht[i][j];
            ca=ca+j*ht[i][j];
        }
        if(rmv>0)
        {
            loop(j,1,201)
            {
                if(cost[j]>=rmv)
                {
                    pa=pa+(rmv)*j;
                    break;
                }
                else
                {
                    pa=pa+j*cost[j];
                    rmv=rmv-cost[j];
                }
            }
        }
        fa=miN(fa,pa);
        total=total-ht[i][0];

    }
    cout<<fa<<"\n";
    return 0;
}


