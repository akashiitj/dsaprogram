#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

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

#define F first
#define S second

int a[2001];

int ht[1000001];

int main()
{
    int n;
    int ans=0;
    int x,pos;
    int l;
    int h,m;
    while(true)
    {
        le(n);
        ans=0;
        if(n==0)break;
        loop(i,0,n)
        le(a[i]);

        sort(a,a+n);

        memset(ht,0,sizeof(ht));

        loop(i,0,n)
        ht[a[i]]=i;

        int l,r;

        loop(i,0,n-2)
        {
            loop(j,i+1,n-1)
            {
                x=a[i]+a[j];
                l=j+1;
                r=n-1;
               // cout<<a[i]<<" "<<a[j]<<" "<<x<<"\n";
                while(l<=r)
                {
                    int m=(l+r)/2;

                    if(a[m]==x)
                    {
                       l=m;
                       break;
                    }
                    else if (x>a[m])
                        l=m+1;
                    else r=m-1;
                }

              //  cout<<r<<" p"<<ans<<" ";
                if(r<j+1)

                {
                    //cout<<"  a1 "<<ans<<" ";
                    ans=ans+0;
                }
                else if(a[r]==x)
                {
                    ans=ans+ht[x]-j;
                    //cout<<"  a2 "<<ans<<" ";
                }
                else{
                    ans=ans+r-j;
                    //cout<<"  a3 "<<ans<<" ";
                }
                    //cout<<ans<<" end\n";

            }
        }
        //cout<<ans<<" 1\n";
        ans=((n*(n-1)*(n-2))/6)-ans;
        cout<<ans<<"\n";
    }
    return 0;
}

