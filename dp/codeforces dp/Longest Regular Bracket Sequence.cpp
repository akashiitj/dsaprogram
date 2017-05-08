
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
    string s;
    cin>>s;
    int n=s.length();
    int match[n];
    int dp[n];
    vi v;
    loop(i,0,n)
    {
        if(s[i]=='(')
           v.pb(i),match[i]=-1,dp[i]=-1;
        else{
            if(v.size()==0)
                match[i]=-1,dp[i]=-1;
            else{
                match[i]=v.back();
                v.pop_back();
                if(match[i]-1>=0&&dp[match[i]-1]!=-1)dp[i]=dp[match[i]-1];
                else dp[i]=match[i];
            }
        }
    }
    int ans=0;
    loop(i,0,n)
    {
       if(dp[i]!=-1) ans=maX(ans,i-dp[i]+1);
    }
    int c=0;
    if(ans>0)
    loop(i,0,n)
    {
        if(dp[i]!=-1 && ans==i-dp[i]+1)c++;
    }
    if(ans==0)
        cout<<"0 1\n";
    else
        cout<<ans<<" "<<c<<"\n";

    return 0;
}


