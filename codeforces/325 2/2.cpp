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
     int n,m;
     le2(n,m);
     string s;
     cin>>s;
     char c[26];
     loop(i,0,26)
     c[i]=(char)('a'+i);
     char a,b;
     loop(i,0,m)
     {
        cin>>a>>b;
        loop(j,0,26)
        {
            if(c[j]==a)c[j]=b;
           else if(c[j]==b)c[j]=a;
        }

     }
     loop(i,0,n)
     {
         s[i]=c[s[i]-'a'];
     }
     cout<<s<<"\n";
    return 0;
}



