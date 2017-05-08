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

int hs[100001];
int hb[100001];

int main()
{
    int n,s;
    le2(n,s);
    char c;
    int x,y;
    loop(i,0,n)
    {
       cin>>c;
       le2(x,y);

       if(c=='B')
            hb[x]=hb[x]+y;
       else
       {
           hs[x]=hs[x]+y;
       }
    }
    int c1=0,ansi=100000;
    for(int i=0;i<=100000;i++)
    {
        if(hs[i]!=0)c1++;
        if(c1==s)
        {
            ansi=i;
            break;
        }
    }

     for(int i=ansi;i>=0;i--)
    {
        if(hs[i]!=0)
        {
            cout<<'S'<<" "<<i<<" "<<hs[i]<<"\n";
        }
    }
    c1=0;
    for(int i=100000;i>=0;i--)
    {
        if(hb[i]!=0)
        {
            cout<<'B'<<" "<<i<<" "<<hb[i]<<"\n";
            c1++;
          //  cout<<c1<<" "<<s<<" ls\n";
            if(c1>=s)
                break;
        }
    }





    return 0;
}


