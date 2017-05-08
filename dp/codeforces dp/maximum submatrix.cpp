
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
int dp[5050][5050]= {};//no of ending on i index having j length bacward

int main()
{
    char s[5050];
    int n,m;
    le2(n,m)
    int d;
    loop(i,0,n)
    {
        scanf("%s", s);
        d=0;
        loop(j,0,m)
        {
            if(s[j]=='0')
                d=0;
            else if(s[j]=='1')
            {
                d++;
                dp[j][d]++;
            }
        }
    }

    int ans=0;
    loop(i,0,m)
    {
        for(int j=i+1; j>=1; j--)
        {
            dp[i][j]+=dp[i][j+1];//
            ans=maX(ans,dp[i][j]*j);
        }
    }
    cout<<ans<<"\n";

    return 0;
}


