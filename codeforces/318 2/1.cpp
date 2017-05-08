
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

#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf(" %I64d",&x);
#define le2ll(x,y) scanf(" %I64d%I64d",&x,&y);

#define F first;
#define S second;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

priority_queue<int > pq;

int main()
{
    int n;
    le(n);
    int x;
    le(x);
    int y;
    loop(i,1,n)
    {
        le(y);
        pq.push(y);
    }

    if(x>pq.top())
    {
        cout<<"0\n";
        return 0;
    }
    int t1,t2;
    int fa=0;
    while(true)
    {
        t1=pq.top();
        pq.pop();
        x=x+1;
        t1=t1-1;
        fa++;
        if(x>t1)
        {
            cout<<fa<<"\n";
            return 0;
        }
        pq.push(t1-1);
    }

    return 0;
}


