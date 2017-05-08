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

vector<ll> a;
vector<ll> cs;

float fsqrt(float x){float xhalf=0.5f*x;int32_t i=*(int32_t*)&x;i=0x5f375a86-(i>>1);x=*(float*)&i;x=x*(1.5f-xhalf*x*x);return 1/x;}

int main()
{
    fast;
    //declare variable here
    ll n;
    frmlty
    {  cin>>n;
       ll x,y;
       cin>>x;
       ll ans=0;
       ll c=0;
       ll y1;
       loop(i,1,n)
       {cin>>y;

        if((y-x)!=0)
        {
             ans++;
             c=1;
        }
        if(c==1&&(y-x)==0)
        {
            ans++;
            c=0;
        }

        x=y;

       }
       if(c==1)
        ans++;
       cout<<ans<<endl;


    }



return 0;
}


