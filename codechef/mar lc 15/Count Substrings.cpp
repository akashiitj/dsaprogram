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
    int x,y,k,n,pl,ans,p,c;
    frmlty
    {
        cin>>x>>y>>k>>n;
        pl=x-y;
        ans=0;
        loop(i,0,n)
        {
            cin>>p>>c;
            if(p>=pl&&c<=k)
                ans=1;
        }
        if(ans==1)cout<< "LuckyChef"<<endl;
        else cout<<"UnluckyChef"<<endl;
    }
    return 0;
}
