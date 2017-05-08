
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
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);


int main()
{
    int n,x;
    le(n);
    vi v1,v2;
    loop(i,0,n)
    {
        le(x);
        if(x%2==0)v1.pb(x);
        else v2.pb(x);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int s1=0,s2=0;
    loop(i,0,v1.size())
    {

        cout<<v1[i]<<" ";
        s1=s1+v1[i];
    }
    cout<<s1<<" ";
    loop(i,0,v2.size())
    {

        cout<<v2[i]<<" ";
        s2=s2+v2[i];
    }
    cout<<s2<<" \n";
    return 0;
}

