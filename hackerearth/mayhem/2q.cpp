#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

int mod= 1000000007;

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

int main()
{
    int n,k;
    char c[21];
    frmlty
    {
        int has[21][26]={};
        le2(n,k);

        loop(i,0,n)
        {
            scanf("%s",c);
            loop(i,0,k)
            {
                has[i][c[i]-'a']++;
            }
        }
        int ans=0,min1,ans2,ansi;
        loop(i,0,k)
        {
            min1=mod;
            loop(j,0,26)
            {
                ans2=0;
                loop(k,0,26)
                ans2=ans2+abs((j-k)*has[i][k]);
                if(ans2<min1)
                {
                    min1=ans2;
                    ansi=j;
                }
            }
            c[i]=ansi+'a';
        }
        cout<<c<<endl;


    }
    return 0;
}

