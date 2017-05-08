
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

ll hcf(ll n1, ll n2)
{
    if (n2!=0)
       return hcf(n2, n1%n2);
    else
       return n1;
}

int main()
{
    fast;
    //declare variable here
    frmlty
    {
      ll a,b;
      cin>>a>>b;
      ll x=-1;
      while(x!=1)
      {   x=hcf(a,b);
          if(x==1)break;
          while(b%x==0)b=b/x;

      }
      if(b==1)cout<<"Yes"<<endl;
      else cout<<"No"<<endl;

    }
      return 0;
}
