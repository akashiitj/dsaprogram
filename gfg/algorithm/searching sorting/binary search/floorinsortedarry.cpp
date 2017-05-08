
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

int a[100];




int main()
{
    int n,l,h,m,ansi,x;
    le(n);
    loop(i,0,n)
    le(a[i]);

    le(x);


    l=0;
    h=n-1;
    int flag=0;
    while(l<=h)
    {
        m=(l+h)/2;

        if(a[m]<x)
        {
            l=m+1;
        }
        else//a[m]>=x
        {
            if(m>=1&&a[m-1]<=x)//since a[m]>=x
            {
                cout<<a[m-1]<<"\n";
                flag=1;
                break;
            }
            h=m-1;

        }

    }
    if(flag==0)cout<<a[l-1]<<"\n";//corner case 1 3 5 7 9  and x=10;




    return 0;
}
