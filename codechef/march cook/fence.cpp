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

int x[100001];

int main()
{
    fast;
    //declare variable here
    int n,k,influence,ans=0;
    string s;
    frmlty
    {
     influence=0;
     ans=0;
     cin>>n>>k;
     cin>>s;
     loop(i,0,n)x[i]=0;

     loop(i,0,n)
     {
         influence=influence+x[i];
         int temp=influence+(s[i]=='R');
         if(temp&1){
            ans++;
            influence++;
            x[min(i+k,n)]=x[min(i+k,n)]-1;
         }
     }
     cout<<ans<<endl;
    }
      return 0;
}

