
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


int main()
{
    int n;
    int a[25];
    a[0]=1;
    loop(i,1,25)
    a[i]=a[i-1]*2;
    int ans=0;
    frmlty
    {
        le(n);

        if(n%2==0)
        {   int flag=0;
            int l;
            ans=0;
            for(int i=24;i>=0; i--)
            {
                if((n&a[i])==0&&flag==0){l=i;continue;}
                flag=1;

                if((n&a[i])!=0)ans+=a[l-1-i];
               // int x=n&a[i];
              //  cout<<i<<" "<<x<<" "<<ans<<"\n";
            }
            printf("%d\n",ans);
        }
        else printf("%d\n",n);
    }
    return 0;
}
