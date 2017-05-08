
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

#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf(" %I64d",&x);
#define le2ll(x,y) scanf(" %I64d%I64d",&x,&y);

#define F first;
#define S second;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

int a[5001]= {};

int f(int l,int r)
{
    if(l==r)return 1;

    int mi=INT_MAX;
    loop(i,l,r+1)
    mi=miN(mi,a[i]);
    //ans2=mi;
    loop(i,l,r+1)
    a[i]=a[i]-mi;

    int p1=l;
    while(p1!=r+1)
    {
        while(p1<(r+1)&&a[p1]==0)//you forgor first condition
            p1++;
        int p2=p1;
        while(p2<(r+1)&&a[p2]!=0)
            p2++;
        mi=mi+f(p1,p2-1);
       // cout<<p1<<" "<<p2<<" "<<ans2<<"\n";
        p1=p2;
    }
    return miN(r-l+1,mi);




}

int main()
{   int n;
    le(n);
    loop(i,1,n+1)
    le(a[i]);

    cout<<f(1,n)<<"\n";

    return 0;
}


