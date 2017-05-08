

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

int ht[1000001]={};

int main()
{
    int k;
    le(k);
    string s;
    cin>>s;
    int n=s.length();
    ht[0]=1;
    int cs=0;
    loop(i,0,n)
    {
        cs=cs+s[i]-'0';
        ht[cs]++;
    }
    ll ans=0;
//    loop(i,0,10)
//    cout<<ht[i] <<" ";
//    cout<<"\n";
    loop(i,k,1000001)
    {  if(k==0&&ht[i]>=2)ans=ans+((((ht[i]-1)*1LL*(ht[i]-2))/2)*(ht[i]>=2))+ht[i]-1;
       if(k!=0) ans=ans+(ll)(ht[i]*1LL*ht[i-k]);

    }
    cout<<ans<<"\n";
    return 0;
}


