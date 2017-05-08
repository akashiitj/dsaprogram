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

#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

int Y[50000][20]= {};
int M[50000][20];

//int S[16]={0,1,2,3,3,4,5,6,6,7,8,9,9,10,11,12};
int S[100000];
bool DP(int mask, int x , int y)
{
    if(x > y)
        x^=y^=x^=y;

    if(S[mask]!=x*y)
        return false;

    if((mask & (mask-1)) == 0)
        return true;

    if(Y[mask][y])
        return M[mask][y];

    Y[mask][y] = 1;


    for(int mask1 =((mask-1)& mask); mask1; mask1 = ((mask1-1) & mask))
    {
        if((S[mask1] % x == 0) && DP(mask1,x,S[mask1]/x) && DP(mask-mask1,x,S[mask-mask1]/x))
        {
            M[mask][y] = 1;
            return 1;
        }
        if((S[mask1] % y == 0) && DP(mask1,y,S[mask1]/y) && DP(mask-mask1,y,S[mask-mask1]/y))
        {
            M[mask][y] = 1;
            return 1;
        }
    }
    M[mask][y] = 0;
    return 0;
}


int main()
{   int cn=0;
    int n;
    int x,y;
    while (true)
    {   cn++;
        le(n);
        if(n==0)break;
        Y[50000][20]= {};
        int a[n];
        le2(x,y);
        loop(i,0,n)
        le(a[i]);


        loop(i,0,1<<n)
        {
            S[i]=0;


            loop(j,0,n)
            {
                if(i & 1<<j)
                {

                    S[i]=S[i]+a[j];

                }


            }

        }

      if(DP(((1<<n)-1),x,y))
        printf("Case %d: Yes\n",cn);
      else printf("Case %d: No\n",cn);

    }
    return 0;
}



