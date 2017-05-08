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

int mark[1001];//0 indicate it is prime 1 indicate its not prime
void seive(int sz)
{


    for(int i=2; i<1001; i++)
    {
        if(mark[i]==0)
        {

            for(int j=i*i; j<=sz; j=j+i)
            {
                mark[j]=1;
            }
        }
    }

}
vi v;
int main()
{
    int n;
    le(n);
    seive(1001);
    loop(i,2,n+1)
    {   int di=i;
        if(mark[di]==0)
        {   while(di<=n)
           {

            v.pb(di);
            di=di*i;
        }
        }
    }
    cout<<v.size()<<"\n";
    loop(i,0,v.size())
    cout<<v[i]<<" ";

    cout<<"\n";

}
