
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


int main()
{   char ch;
    int r[1235];
    int c[5679];
    int htr[1235];
    int htc[5679];

    loop(i,1,1235)
    {
        r[i]=i;
        htr[i]=i;
    }

    loop(i,1,5679)
    {
        c[i]=i;
        htc[i]=i;
    }
    int x,y;
    int ans;
    while(~scanf(" %c",&ch))
    {
        if(ch=='R')
        {
            le2(x,y);
            swap(r[x],r[y]);
            htr[r[x]]=x;
            htr[r[y]]=y;
        }
       else if(ch=='C')
        {
            le2(x,y);
            swap(c[x],c[y]);
            htc[c[x]]=x;
            htc[c[y]]=y;
        }
        else if(ch=='Q')
        {
            le2(x,y);
            ans=(r[x]-1)*5678;
            ans+=c[y];
            printf("%d\n",ans);
        }
        else{
            le(ans);
            if(ans%5678==0)
                x=(ans/5678)-1;
            else x=ans/5678;

            y=ans-(x*5678);
            printf("%d %d\n",htr[x+1],htc[y]);
        }
    }
    return 0;
}

