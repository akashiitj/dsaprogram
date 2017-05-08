
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

int bck[300][100001];
int mx[300];
int a[100001];
int n,m,l,r;

void f()
{
    loop(i,1,n+1)
    {
        bck[i/400][a[i]]++;
        mx[i/400]=maX(mx[i/400],a[i]);
    }
}

int main()
{

    le2(n,m);

    loop(i,1,n+1)
    le(a[i]);

    f();

    int lb;
    int ub;
    int pmx,ans;

    loop(i,0,m)
    {
        le2(l,r);
        lb=l/400;
        ub=r/400;
        pmx=0;
        ans=0;

        if(lb==ub)
        {

            loop(j,l,r+1)
            pmx=maX(pmx,a[j]);

            loop(j,l,r+1)
            if(a[j]==pmx)ans++;

            printf("%d\n",ans);


        }
        else
        {

           //finding max element
            loop(j,l,(lb+1)*400)
            pmx=maX(pmx,a[j]);

            loop(j,lb+1,ub)
            pmx=maX(pmx,mx[j]);

            loop(j,ub*400,r+1)
            pmx=maX(pmx,a[j]);


            //finding its frequency
            loop(j,l,(lb+1)*400)
            if(a[j]==pmx)ans++;

            loop(j,lb+1,ub)
            ans=ans+bck[j][pmx];

            loop(j,ub*400,r+1)
            if(a[j]==pmx)ans++;

            printf("%d\n",ans);
        }
    }

    return 0;
}

