
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


int main()
{
    int n,m,d;
    le2(n,m);
    le(d);

    int a[n*m];
    int x=0;
    int hv;
    int flag=0;
    loop(i,0,n)
    loop(j,0,m)
    {

        le(a[x]);
        hv=a[0]%d;
        //cout<<a[x]%m<<" "<<a[x]<<"\n";
        if(hv!= (a[x]%d))flag=1;//first you are doing a[x]%m and got wrong ans;
        x++;
    }
   // cout<<flag<<" ";
    if(flag==1)
    {
        cout<<"-1"<<"\n";
        return 0;
    }
    n=m*n;
    sort(a,a+n);
    if(n%2==0)
    {
        int ans=0,ans1=0;
        loop(i,0,n)
        {
            ans=ans+abs(a[i]-a[n/2]);
            ans1+=abs(a[i]-a[(n/2)+1]);
        }
        cout<<min(ans,ans1)/d<<"\n";
        return 0;

    }

    int ans=0;
    loop(i,0,n)
    {
        ans=ans+abs(a[i]-a[n/2]);
        //ans1+=bs(a[i]-a[(n/2)+1]);
    }
    cout<<ans/d<<"\n";

    return 0;
}


