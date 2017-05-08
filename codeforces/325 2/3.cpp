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

int main()
{
    int n;
    le(n);
    int a[n+1];
    loop(i,0,n)
    {
        le(a[i]);
    }
    if(a[n-1]==0)a[n]=0;
    else a[n]=1;
    int i=0,j;
    int pre;
    int ans=0;
    while(i<n)
    {
        if(a[i]==0)
        {
            j=i+1;
            pre=0;
            while(i<=n&&a[j]!=pre)
            {
                pre=a[j];
                j++;
            }
             if(j-i>=2)
            {
                int hv=j-i;
                if(hv%2==0)
                {
                    ans=max(ans,(hv/2)-1);
                    int chv=0;
                    for(int i1=i; i1<j; i1++)
                    {
                        if(chv<(hv/2))
                        {
                            a[i1]=0;
                            chv++;
                        }
                        else a[i1]=1;
                    }
                }
                else
                {
                    ans=max(ans,(hv/2));
                    int chv=0;
                    for(int i1=i; i1<j; i1++)
                    {
                        a[i1]=0;
                    }
                }
            }
            i=j;
        }
        else if(i<n&&a[i]==1)
        {
            j=i+1;
            pre=1;
            while(i<=n&&a[j]!=pre)
            {
                pre=a[j];
                j++;
            }
            if(j-i>=2)
            {
                int hv=j-i;
                if(hv%2==0)
                {
                    ans=max(ans,(hv/2)-1);
                    int chv=0;
                    for(int i1=i; i1<j; i1++)
                    {
                        if(chv<(hv/2))
                        {
                            a[i1]=1;
                            chv++;
                        }
                        else a[i1]=0;
                    }
                }
                else
                {
                    ans=max(ans,(hv/2));
                    int chv=0;
                    for(int i1=i; i1<j; i1++)
                    {
                        a[i1]=1;
                    }
                }
            }
            i=j;
        }
    }
    cout<<ans<<"\n";
    loop(i,0,n)
    printf("%d ",a[i]);

    return 0;
}



