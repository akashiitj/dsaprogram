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
    {
        vector<ll> a;
        vector<ll> cs;
        a.push_back(1);
        cs.push_back(1);
       // cout<<cs[cs.size()-1]<<endl;
        cin>>n;
        ll pre=1;
        while(n%2==0)
        {

            if(pre!=2)
            {
                a.push_back(cs[cs.size()-1]*2);
                ll cs1=cs[cs.size()-1]+a[a.size()-1];
                cs.push_back(cs1);
                pre=2;
            }
            else
            {
                ll sum=a[a.size()-1]*2;
                a.push_back(sum);
                ll cs1=cs[cs.size()-1]+a[a.size()-1];
                cs.push_back(cs1);
            }
            n = n>>1;

        }
        for(int i=3; i<=fsqrt(n); i=i+2)
        {

            while(n%i==0)
            {
                if(pre!=i)
            {
                a.push_back(cs[cs.size()-1]*i);
                ll cs1=cs[cs.size()-1]+a[a.size()-1];
                cs.push_back(cs1);
                pre=i;
            }
            else
            {
                ll sum=a[a.size()-1]*i;
                a.push_back(sum);
                ll cs1=cs[cs.size()-1]+a[a.size()-1];
                cs.push_back(cs1);
            }
             n = n/i;
            }

        }

        if (n > 2 )
        {
            if(pre!=n)
            {
                a.push_back(cs[cs.size()-1]*n);
                ll cs1=cs[cs.size()-1]+a[a.size()-1];
                cs.push_back(cs1);
                pre=n;
            }
            else
            {
                ll sum=a[a.size()-1]*n;
                a.push_back(sum);
                ll cs1=cs[cs.size()-1]+a[a.size()-1];
                cs.push_back(cs1);
            }

        }
           cout<<cs[cs.size()-1]<<endl;

    }



return 0;
}

