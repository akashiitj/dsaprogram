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



int main()
{
    int  n, l, r, x ;
    cin>>n>>l>>r>>x;

    int a[n];
    loop(i,0,n)
    cin>>a[i];

    sort(a,a+n);
    int mi,ma,to;
    int ans=0;
    loop(i,0,1<<n)
    {
        mi=10000000;
        ma=-1;
        to=0;
        loop(j,0,n)
        {
            if(i & 1<<j)
            {
                mi=min(a[j],mi);
                ma=max(a[j],ma);
                to=to+a[j];
            }
        }
        if(ma-mi>=x&&to>=l&&to<=r)
            ans++;

    }


    cout<<ans<<"\n";

    return 0;
}

