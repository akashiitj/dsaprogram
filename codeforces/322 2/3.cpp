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

pii a[100001];

int main()
{
    int n,k;
    le2(n,k);

    loop(i,0,n)
    {
        le(a[i].second);
        a[i].first=a[i].second%10;
    }

    sort(a,a+n);
    reverse(a,a+n);

    loop(i,0,n)
    {
        if(a[i].first==0)break;
        if(k>=10-a[i].first)
        {
            a[i].second+=(10-a[i].first);
            k=k-(10-a[i].first);
        }
        else break;
    }
    int req;
    if(k>0)
    {
        loop(i,0,n)
        {
            if(a[i].second<100&&k>0)
            {
                req=100-a[i].second;
                if(k>=req)
                {
                    a[i].second=100;
                    k=k-req;
                }
                else
                {
                    a[i].second=a[i].second+k;
                    break;
                }
            }
        }

    }

    int ans=0;
    loop(i,0,n)
    ans=ans+a[i].second/10;

    cout<<ans<<"\n";
    return 0;
}



