

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

int main()
{
    int n,k;
    le2(n,k);
    int a[n];
    int cs[n+1];
    cs[0]=0;
    loop(i,0,n)
    {
        le(a[i]);
        cs[i+1]=cs[i]+a[i];
    }
    int mi=INT_MAX;
    int ai;
    loop(i,k,n+1)
    {
      //  cout<<mi<<" "<<cs[i]-cs[i-k]<<" "<<i<<" "<<i-k<<"\n";
        if(mi>cs[i]-cs[i-k])
        {
            ai=i-k+1;
            mi=cs[i]-cs[i-k];
        }

    }
    cout<<ai<<"\n";
    return 0;
}

