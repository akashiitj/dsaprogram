
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

int prnt[20001];//helps in backtracking
int val[20001];

void solve(int n)
{
    queue<int> q;
    q.push(1%n);
    prnt[1%n]=0;
    val[1%n]=1;
    int x;
    while(true)
    {
        x=q.front();
        q.pop();
        if(x==0)
        {
            stack<int> stk;
            while(prnt[x]!=0)//jab tak hum 1 pe nahi pahuch jate
            {
                stk.push(val[x]);
                x=prnt[x];

            }
            stk.push(1);//remember this
            while(stk.size()!=0)
            {
                cout<<stk.top();
                stk.pop();
            }
            cout<<"\n";
            return ;
        }

        int t=(x*10)%n;
        if(prnt[t]==-1)
        {   q.push(t);
            prnt[t]=x;
            val[t]=0;
        }
        t=(x*10+1)%n;
        if(prnt[t]==-1)
        {   q.push(t);
            prnt[t]=x;
            val[t]=1;
        }
    }
}


int main()
{
    int n;
    frmlty
    {
        le(n);

        loop(i,0,n+1)
        prnt[i]=-1;
        solve(n);
    }

    return 0;
}

