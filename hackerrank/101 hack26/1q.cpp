
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
    string s;
    cin>>s;
    int h[26];
    loop(j,0,26)
    h[j]=0;
    loop(i,0,s.length())
    {
        h[s[i]-'a']++;
    }


    sort(h,h+26);
    int i=0;


    while(h[i]==0)
        i++;

    // cout<<i<<endl;
    int gh=0;
    loop(x,i,25)
    if(h[x]!=h[x+1])
        gh=1;
    if(gh==0)
        cout<<"YES\n";
    else
    {
        loop(x,i,26)
        {
            h[x]--;
            int gh=0;
            map<int,int> ma;
            loop(x,i,26)
            {

                if(h[x]!=0)
                    ma[h[x]]++;
            }
            h[x]++;
            //  cout<<ma.size()<<" "<<x<<endl;
            if(ma.size()==1)
            {
                // cout<<x<<endl;
                cout<<"YES\n";
                return 0;
            }
        }
        cout<<"NO\n";
    }


    return 0;
}

