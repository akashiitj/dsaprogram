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
#define B 320

#define F first
#define S second
int a[100005],b[330],c[330][100005];
int main()
{
    ios_base::sync_with_stdio(false);
    int n,q;
    le2(n,q);

    loop(i,0,n)
    {
        le(a[i]);
        b[i/B] = maX(b[i/B],a[i]);
        c[i/B][a[i]]++;
        //m[pii(i/B,a[i])]++;
    }
    while(q--)
    {
        int l,r;
        le2(l,r);
        l--;
        r--;
        int p = l/B;
        int q = r/B;
        int mx=0;
        if(p==q)
        {
            loop(i,l,r+1)
            {
                mx = max(mx,a[i]);
            }
        }
        else
        {
            loop(i,l,(p+1)*B)

            {
                mx = max(mx,a[i]);
            }

            loop(i,p+1,q)

            {
                mx = max(mx,b[i]);
            }

            loop(i,q*B,r+1)

            {
                mx = max(mx,a[i]);
            }
        }
        int cnt=0;
        if(p==q)
        {
            for(int i=l; i<=r; i++)
            {
                if(a[i]==mx)cnt++;
            }
        }
        else
        {
            for(int i=l; i<=(p+1)*B-1; i++)
            {
                if(a[i]==mx)cnt++;
            }
            for(int i=p+1; i<q; i++)
            {
                //cnt = cnt + m[pii(i,mx)];
                cnt = cnt + c[i][mx];
            }
            for(int i=q*B; i<=r; i++)
            {
                if(a[i]==mx)cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
