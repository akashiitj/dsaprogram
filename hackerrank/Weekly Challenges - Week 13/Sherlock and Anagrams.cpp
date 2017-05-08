#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(ull i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;
const ull N = 10000001;
const ull mod = 1000000007;

ull sum(ull n)
{
    if(n<=1)return 0;
    return (n*(n-1))/2;
}
int main()
{   std::ios_base::sync_with_stdio(false);
    ull t;
    string s,s1;
    cin>>t;
    ull n;
    ull ans;
    while(t--)
    { cin>>s;
      n=s.length();
      map<string,ull> m;
      loop(i,1,n)
      {
          loop(j,0,n-i+1)
          {
              s1=s.substr(j,i);
              sort(s1.begin(),s1.end());
              m[s1]++;
          }
      }
      ans=0;
      for( map<string,ull>::const_iterator it = m.begin(); it != m.end(); ++it )
    {
      ans=ans+sum(it->second);
    }
    cout<<ans<<endl;
    }
    return 0;
}

