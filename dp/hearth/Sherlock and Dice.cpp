
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

 double dp[50+1][10000+1];

int main()
{
    int m,sum;
    double n;
    frmlty
    {
        le(m);
        cin>>n;
        le(sum);

        loop(i,0,50+1)
        loop(j,0,10000+1)
        dp[i][j]=0.0;

        loop(i,1,miN((int)n+1,sum+1))
        dp[1][i]=1.0/n;

        loop(i,2,m+1)
        {
            loop(j,1,sum+1)
            {
                dp[i][j]=0.0;
                loop(k,1,min(j,int(n+1)))
                dp[i][j]+=((1.0/n)*dp[i-1][j-k]);
              //  dp[i][j]/=n;

                //cout<<dp[i][j]<<" ";
            }
            //cout<<"\n";
        }
        if(dp[m][sum]==0.0)
            cout<<"0.000 0\n";
        else{
            double hv=dp[m][sum];
            int c=0;
            while(hv<1.0)
            {
                hv=hv*10.0;
                c++;
            }
            cout<<fixed<<setprecision(3);
            cout<<hv<<" "<<c<<"\n";
        }


    }
    return 0;
}

