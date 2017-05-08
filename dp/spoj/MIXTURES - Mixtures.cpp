
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

ll dps[101][101];
int sum[101][101];
int m[101];

int main()
{
    int n;
    while(cin>>n)
    {

        loop(i,1,n+1)
        le(m[i]);

        loop(i,1,n+1)
        {
            dps[i][i]=0;
            sum[i][i]=m[i];
        }

        loop(i,1,n)
        {
            dps[i][i+1]=sum[i][i]*1LL*sum[i+1][i+1];
            sum[i][i+1]=(sum[i][i]+sum[i+1][i+1])%100;
        }

        loop(l,3,n+1)
        {
            loop(i,1,n-l+1+1)
            {
                dps[i][i+l-1]=100000000000000LL;
                loop(j,i,i+l-1)
                {
                    ll x=dps[i][j]+dps[j+1][i+l-1]+sum[i][j]*1LL*sum[j+1][i+l-1];
                    if(x<dps[i][i+l-1])
                    {
                        dps[i][i+l-1]=x;
                        sum[i][i+l-1]=(sum[i][j]+sum[j+1][i+l-1])%100;
                    }



                }
               // cout<<dps[i][i+l-1]<<" ";
            }
            //cout<<"\n";
        }
        cout<<dps[1][n]<<"\n";

    }
    return 0;
}


