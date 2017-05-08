
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;


#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<ll>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair

#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

#define F first
#define S second

int a[100]= {};
int n=3;
// we are not memorizing its not dp;
int f(int s,int idx)//idx to store in which index of array we put i
{
    int ans=0;
    if(s==0)
    {
        int x=0;
        while(x<idx)
            cout<<a[x++]<<" ";
        cout<<endl;
        return 1;
    }
    else if(s>0)
    {
        loop(i,1,n+1)
        {

            a[idx]=i;
            ans=ans+f(s-i,idx+1);
        }
        return ans;
    }
    else return 0;
}

int main()
{
    int s;
    cin>>s;
    cout<<f(s,0);
    return 0;
}

