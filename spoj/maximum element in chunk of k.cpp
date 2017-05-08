#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

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

int a[1000001];
deque<int> q;

int main()
{
    int n,k;
    le(n);
    loop(i,0,n)
    {
        le(a[i]);
    }
    le(k);

    loop(i,0,n)
    {
        if(q.size()==0)
            q.push_back(i);
        else
        {
            while(q.size()!=0&&i-q.front()>=k)q.pop_front();//remove element ehich are not going to be part of this window when you have element in dec order
            while(q.size()!=0&&a[i]>a[q.back()])q.pop_back();//if present element is greater than obviously it is good to keep it
            q.push_back(i);
        }
        if(i>=k-1)  printf("%d ",a[q.front()]);
    }
    cout<<"\n";
    return 0;
}


