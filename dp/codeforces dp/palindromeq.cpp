
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

ll dp[2001]= {};
ll dpb[2003]= {};
int main()
{
    string s;
    cin>>s;
    s="0"+s;
    // cout<<s<<"\n";
    int    n=s.length()-1;
    int x=1;
    loop(i,1,n+1)
    {
        dp[i]+=1;
        dpb[i]+=1;
        x=1;
        while(((i-x)>0)&&((i+x)<=n)&&(s[i-x]==s[i+x]))
        {
            dp[i+x]++;

            dpb[i-x]++;
            x++;
        }
    }
//    loop(i,1,n+1)
//    {
//        cout<<dp[i]<<" ";
//    }
//    cout<<"\n";
//
//    loop(i,1,n+1)
//    {
//        cout<<dpb[i]<<" ";
//    }
//    cout<<"\n";

    int j,i1;
    loop(i,1,n)
    {
        j=i+1;
        i1=i;
        while(i1>0&&j<=n&&s[i1]==s[j])
        {
            dp[j]++;

            dpb[i1]++;
            i1--;
            j++;

        }
    }
    dpb[s.length()]=0;
    for(int i=s.length()-1; i>=1; i--)
        dpb[i]+=dpb[i+1];

    ll ans=0;
    loop(i,1,n)
    ans=ans+dp[i]*dpb[i+1];

    cout<<ans<<"\n";

    return 0;
}


