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

int a[100001];
int ans[100001];

int main()
{

    int n;
    int l;
    int r;
    int x;
    frmlty
    {
        le(n);
        loop(i,1,n+1)
        le(a[i]);

        ans[1]=a[1];
        int lo=1,ro=1;
        l=1;
        r=1;
        loop(i,2,n+1)
        {
            x=a[i];
            l=lo;
            r=ro;
            while(l<=r)
            {
                int m=(l+r)/2;

                if(ans[m]==x)
                {
                    l=m+1;
                }
                else if (x>ans[m])
                    l=m+1;
                else r=m-1;
            }

            if(l>ro)
            {
                ro++;
                ans[ro]=x;
            }
            else ans[l]=x;

            //cout<<l<<" "<<r;// l gives you ceil r gives you floor

        }
        cout<<ro<<" ";
        loop(i,1,ro+1)
        cout<<ans[i]<<" ";
        cout<<"\n";

    }
    return 0;
}


