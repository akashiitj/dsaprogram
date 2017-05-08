
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

#define fast      ios_base::sync_with_stdio(false)
#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<LL>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair



#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define mod       1000000007

int main()
{
    fast;
    //declare variable here
    string s;
    int n;
    frmlty
    {
        cin>>s;
        cin>>n;
        ll c=0;
        loop(i,0,s.length())
        {
            if(s[i]=='T')
                c=c+2;
            else c=c+1;
        }
        int i=1;
        ll ans=0;
        //cout<<c<<endl;
        while(c*i<=(12*n))
        {  // cout<<i<<endl;
            ans=ans+(12*n)-c*i;
           // cout<<ans<< " a "<<endl;
            i++;
        }
        cout<<ans<<endl;
    }
      return 0;
}
