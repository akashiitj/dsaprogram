// you are given n eggs and k floor find how much minimum trial you need to do to find out from which floor egg will broke
// if you are given 1 egg only then you have to starts from first floor and minimum number of trial is floor number
// but here catch is you have given n eggs
// so for n numbers of eggs if you want to find out number of min trials for kth floor
//so their are 2 case you pick a egg and drop it from first floor then if it break your ans is 1+dp[n-1][0]
//if egg doesnt break 1+dp[n][k-1]//you ans is up floor and yo have all eggs left
// teke example of 2 eggs 3 floor//if we have one egg than answer is 3 but we are making use of 2 eggs
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

int dp[100][100];

int main()
{
    int n,f;
    le2(n,f);
    loop(i,0,n+1)
    {
        dp[i][0]=0;//no matters how much egg you have if you are on 0 floor ans=0

    }
    loop(i,1,f+1)
    {
        dp[1][i]=i;
    }

    loop(i,2,n+1)
    {
        loop(j,2,f+1)
        {   dp[i][j]=INT_MAX;
            loop(k,1,j+1)
            dp[i][j]=miN(dp[i][j],1+maX(dp[i-1][k-1],dp[i][j-k]));
        }
    }
    cout<<dp[n][f]<<"\n";
    return 0;
}

