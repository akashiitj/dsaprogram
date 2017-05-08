
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

    int n;
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl;
        cout<<1<<endl;
    }
    if(n==2)
    {
        cout<<1<<endl;
        cout<<1<<endl;
    }
        if(n==3)
    {
        cout<<2<<endl;
        cout<<1<<" "<<3<<endl;
    }
     if(n==4)
    {
        cout<<4<<endl;
        cout<<3<<" "<<1<<" "<<4<<" "<<2<<endl;

    }
    if(n>=5)
    {
        int i=1;
        cout<<n<<endl;
        while(i<=n)
        {
            cout<<i<<" ";
            i=i+2;
        }
        i=2;
        while(i<=n)
        {
            cout<<i<<" ";
            i=i+2;
        }
        cout<<endl;
    }

      return 0;
}
