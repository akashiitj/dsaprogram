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


int main()
{

    int t1;
    cin>>t1;
    while(t1--)
    {
        ll R,S;
        le2(R,S);
        int t = R / S * S;
        R %= S;
        cout<<t<<" "<<R<<"\n";
        if(4 * R <= S)
        {
            int g = __gcd(R, S);
            cout << t + R;
            R /= g;
            S /= g;
            cout << " " << R << "/" << S << endl;
        }
        else
        {
            cout << t + S << " 0/1" << endl;
        }
    }
    return 0;
}

