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

#define F first
#define S second

ll ways[20];
ll lesser[10] = {0,1,2,2,2,3,3,4,4,5};//lesser than n how many nonprime not including i

int main()
{
    ways[0]=1;

    loop(i,1,19)
    ways[i]=6*ways[i-1];

    ll n,n1;
    ll dp[19];
    dp[0]=0;
    ll cur_digit;
    int i=0;
    int flag;
    frmlty
    {
        dp[0]=0;
        lell(n);
        n1=n;
        i=0;
        flag=0;
        while(n>0)
        {
            i++;
            cur_digit=n%10;
            n=n/10;
            if(cur_digit==2||cur_digit==3||cur_digit==5||cur_digit==7)
            {
                flag=1;//for checking number itself
                dp[i]=lesser[cur_digit]*ways[i-1];
            }
            else
            {
                dp[i]=dp[i-1]+lesser[cur_digit]*ways[i-1];//dp[i-1] becoz cur digit ke saath for ex if 4 than all number dp[i-1] contribute to nas
            }

        }

        if(flag==0)
            dp[i]++;//due to this you waste 1 hour dp[0] get chance to 1;

        n1=n1+1-dp[i];//total number is n+1 - number ehich is not magical
        printf("%lld\n",n1);
    }
    return 0;
}

