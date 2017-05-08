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
    int k;
    string s;
    cin>>k;
    cin>>s;

    int a[27];
    loop(i,0,27)
    a[i]=0;


    vector<int > v;

    loop(i,0,s.length())
    {
        if(a[s[i]-97]==0)
        {   a[s[i]-97]=1;
            v.push_back(i);
        }
    }
    if(k>v.size())
    {
        cout<<"NO"<<endl;
        return 0;
    }
    else
    {
        cout<<"YES"<<endl;
        loop(i,1,k)
        {
            cout<<s.substr(v[i-1],v[i]-v[i-1])<<endl;
        }
        cout<<s.substr(v[k-1])<<endl;
    }
      return 0;
}

