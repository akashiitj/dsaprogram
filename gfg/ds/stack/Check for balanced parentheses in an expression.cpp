#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

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

vector<char> v;



int isbalanced(string s)
{
    int n=s.length();
    loop(i,0,n)
    {
        if(s[i]=='{'||s[i]=='('||s[i]=='[')
            v.pb(s[i]);

        else
        {
            if(s[i]==')' && v.back()!='(')
            {
                return 0;
            }
            if(s[i]==']' && v.back()!='[')
            {
                return 0;
            }
            if(s[i]=='}' && v.back()!='{')
            {
                return 0;
            }
            v.pop_back();
        }
//        loop(i,0,v.size())
//        cout<<v[i]<<" ";
//        cout<<endl;
    }
    if(v.size()!=0)
        return 0;
    return 1;

}


int main()
{
    string s;
    cin>>s;
    cout<<isbalanced(s);
    return 0;
}


