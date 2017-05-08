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
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

int a[17];
int ad[17];
int n,k,m;
int f()
{
    int ma=-1,c;
    int flag=0;//flag 0 means no probleb
    loop(i,0,n-k+1)
    {
        ma=-1;
        c=0;
        loop(j,i,i+k)
        {
            ma=max(ma,a[j]);
        }
        loop(j,i,i+k)
        {
            if(ma==a[j])c++;
            if(c>=m)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)break;
    }
    return flag;
}

int popcount(int x)
{
    int res = 0;
    int l=1;
    while (l<=x)
    {
        if(l & x)res++;
        l=l<<1;
    }
    return res;
}
int main()
{
    frmlty
    {
        le2(n,k);
        le(m);
        loop(i,0,n)
        {
            le(a[i]);
            ad[i]=a[i];
        }
        int ans=n+1;
        int c1;
        loop(i,0,1<<n)
        {
            c1=popcount(i);
            if(c1>=ans)continue;
            loop(j,0,n)
            {
                if(i & 1<<j)
                    a[j]=ad[j]+1;
                else
                    a[j]=ad[j];
            }
            if(f()==0)ans=c1;

        }
        if(ans==n+1)cout<<"-1"<<"\n";
        else  cout<<ans<<"\n";
    }
    return 0;
}

