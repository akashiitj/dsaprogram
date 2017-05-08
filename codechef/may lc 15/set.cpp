#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

#define fast      ios_base::sync_with_stdio(false)
#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<LL>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair



#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define mod       1000000007

ll p2[100001];

int main()
{
    fast;
    //declare variable here
    p2[0]=1;
    loop(i,1,100001)
   {
    p2[i]=p2[i-1]*2;
    if(p2[i]>=mod)p2[i]=p2[i]%mod;
   }
    frmlty
    {   int n;
        cin>>n;
        ll a[n];
        loop(i,0,n)
        cin>>a[i];

        sort(a,a+n);

        ll mins=0;
        ll maxs=0;
        ll ans=0;
        loop(i,1,n+1)
        {


            mins=p2[n-i]*a[i-1];
            if(mins>=mod)mins=mins%mod;
            maxs=p2[i-1]*a[i-1];
            if(maxs>=mod)maxs=maxs%mod;

            if(maxs-mins<0)ans=ans+maxs-mins+mod;
            while(ans<0)ans=ans+mod;
            if(maxs-mins>0) ans=ans+maxs-mins;
            ans=ans%mod;
        }

        ans=ans%mod;

        cout<<ans<<endl;

    }
      return 0;
}
