
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



#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define mod       10000009

int a[101][101];
vi v;

int main()
{
    fast;
    //declare variable here
    int n,ans=0;
    cin>>n;
    loop(i,0,n)
    loop(j,0,n)
    cin>>a[i][j];

    loop(i,0,n)
    {
        int x=0;
        loop(j,0,n)
        {
            if(a[i][j]==1||a[i][j]==3)
            {
                x=1;
                break;
            }

        if(x==0)
        {
            ans++;
            v.push_back(i+1);
        }
    }
    cout<<ans<<endl;
     loop(j,0,v.size())
     cout<<v[j]<<" ";

     if(v.size()!=0)
      cout<<endl;



}
