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
#define lell(x) scanf("%%I64d",&x);
#define le2ll(x,y) scanf("%%I64d%%I64d",&x,&y);


int main()
{   string s,ts;
    cin>>s;
    int n;
    set<string> st;
    n=s.length();
    loop(i,0,n+1)
    {
        loop(j,0,26)
        {
            ts=s;
            ts.insert(i,1,j+'a');
            st.insert(ts);
        }
    }
    cout<<st.size()<<"\n";
    return 0;
}


