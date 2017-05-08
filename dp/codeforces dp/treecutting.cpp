#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;


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

#define F first
#define S second


int ht[100001]= {};
int a[100001];
int dp[100002];
int main()
{
    int n;
    le(n);

    pii a[n];
    loop(i,0,n)
    {
        le2(a[i].F,a[i].S);
    }
    if(n<=2)
    {
        cout<<n<<"\n";
        return 0;
    }
    sort(a,a+n);

    int maxsafer[n],maxsafel[n];

    loop(i,1,n)
    {
        maxsafer[i-1]=a[i].F;
        maxsafel[i]=a[i-1].F;
    }
    int ans=2;
    loop(i,1,n-1)
    {
         if(a[i].S<(-maxsafel[i]+a[i].F))
         {
              ans++;
         }

       else if(a[i].S<maxsafer[i]-a[i].F)
        {
            maxsafel[i+1]=a[i].F+a[i].S;
            ans++;
        }
    }
    cout<<ans<<"\n";


    return 0;
}

