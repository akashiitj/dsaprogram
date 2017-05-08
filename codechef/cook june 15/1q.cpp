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

#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);


int main()
{
     frmlty
     {    int n,k;
         le2(n,k);
         int ns=0;
         int ps=0,nn;
         int x;
         loop(i,0,n)
         {
             le(x);
          //   x=x%2;
             ps=ps+x;
            // ps=ps%2;
         }
         nn=(ps+1)%2;
         loop(i,0,k-1)
         {
             ns=(ps+nn)%2;
             ps=ns;
             nn=(ns+1)%2;
         }
         if(nn==0)
            cout<<"even\n";
         else cout<<"odd\n";

     }
    return 0;
}


