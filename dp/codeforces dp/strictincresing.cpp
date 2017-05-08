
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


int main()
{
    int n;
    le(n);
    int a[n];
    loop(i,0,n)
    le(a[i]);

    if(n<=2)
    {
        cout<<n<<"\n";
        return 0;
    }

    int l[n];
    int r[n];

    l[0]=1;
    loop(i,1,n)
    {
        if(a[i]>a[i-1])
            l[i]=l[i-1]+1;
        else l[i]=1;
    }
    r[n-1]=1;
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]<a[i+1])r[i]=r[i+1]+1;
        else r[i]=1;
    }
    int ans=-1;
    loop(i,1,n-1)
    {
        if(!(a[i]>a[i-1]&&a[i]<a[i+1])&&a[i+1]-a[i-1]>1)
            ans=max(ans,1+l[i-1]+r[i+1]);
        ans=max(ans,max(r[i+1]+1,l[i-1]+1));//you forget this
    }
    ans=max(ans,max(r[1]+1,l[n-2]+1));
    cout<<ans<<"\n";
        return 0;
}


