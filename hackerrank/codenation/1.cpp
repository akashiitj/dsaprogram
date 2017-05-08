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
#define fi first
#define se second


int main()
{
    std::ios_base::sync_with_stdio(false);
    int n,p;
    cin>>n>>p;
    vector<pair<string ,string> > v;
    loop(i,0,p)
    {
        string s1,s2;
        cin>>s1>>s2;
        v.push_back(mp(s1,s2));
    }
    sortv(v);
    string s[p];
    int cou[p];
    loop(i,0,p)
    {
        s[i]="00:00";
        cou[i]=0;
    }
    int ep=0;
    loop(i,0,p)
    {
        int flag=0;
        loop(j,0,ep)
        {
            if(s[j]<=v[i].fi)
            {
                s[j]=v[i].se;
                flag=1;
                cou[j]++;
            }
        }
        if(flag!=1)
        {
            s[ep]=v[i].se;
            cou[ep]++;
            ep++;

        }
    }
    sort(cou,cou+p);
    loop(i,0,p)
    cout<<cou[i]<<" ";

    return 0;
}

