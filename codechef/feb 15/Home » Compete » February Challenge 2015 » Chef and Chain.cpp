#include <bits/stdc++.h>

using namespace std;
#define loop(i,a,b) for(ull i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define sortv(v) sort(v.begin(), v.end())
#define each(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second


int main()
{
    std::ios_base::sync_with_stdio(false);
    string s;
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        ll pi=0;
        ll c=0,c1=0,c2=0;
        char s1='+',s2='-';
        loop(i,0,s.length())
        {
            if(s[i]!=s1)c1++;
            swap(s1,s2);
        }
        s1='-';
        s2='+';
        loop(i,0,s.length())
        {
            if(s[i]!=s1)c2++;
            swap(s1,s2);
        }
        c=min(c1,c2);
        cout<<c<<endl;

    }
    return 0;
}

