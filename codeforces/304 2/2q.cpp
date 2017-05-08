
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



#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define mod       10000009


int main()
{
    fast;
    //declare variable here
    ll n,x;
    cin>>n;
    ll a[n+1];
    loop(i,1,n+1)
    a[i]=0;
    loop(i,0,n)
    {
        cin>>x;
        a[x]++;
    }
    ll cs=0;
    ll ans1=0;
    loop(i,1,n+1)
    {   ans1=ans1+(i*a[i]);
        if(a[i]!=0)
        {
         cs=cs+a[i]-1;
        }
        if(a[i]==0&&cs>0)
        {
            a[i]=1;
            cs--;
        }
    }
    ll ans=0;
    loop(i,1,n+1)
    if(a[i]!=0)ans=ans+i;
    if(cs>0)
    {
        ans=ans+((cs+n)*(cs+n+1))/2-((n)*(n+1))/2;
    }
    cout<<ans-ans1<<endl;



}

