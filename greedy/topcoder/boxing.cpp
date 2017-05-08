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

int maxCredit(vector<int> a, vector<int> b, vector<int> c, vector<int> d, vector<int> e)
{
    int lp[6]= {-1,-1,-1,-1,-1,-1};
    int li[6]= {};
    int ans=0;
    vector<int > h[6];
    h[1]=a;
    h[2]=b;
    h[3]=c;
    h[4]=d;
    h[5]=e;
    // cout<<h[1][0]<<endl;
    loop(i,1,180000+1)
    {
        loop(j,1,6)
        {
            if(h[j].size()>0&&h[j][li[j]]<=i)
            {
                lp[j]=h[j][li[j]];
                li[j]++;
            }
        }
        int c=0;
        loop(j,1,6)
        {
            if(lp[j]!=-1&&i-lp[j]<=1000)c++;
        }
        if(c>=3)
        {
            ans++;
            lp[1]=-1;
            lp[2]=-1;
            lp[3]=-1;
            lp[4]=-1;
            lp[5]=-1;
        }
    }
    return ans;
}


int main()
{

    vector<int > a=   {1,2,3,4,5,6};
    vector<int > b=  {1,2,3,4,5,6,7};
    vector<int > c=  {1,2,3,4,5,6};
    vector<int > d=  {0,1,2};
    vector<int > e=  {1,2,3,4,5,6,7,8};



    cout<<maxCredit(a,b,c,d,e)<<endl;

    return 0;
}

