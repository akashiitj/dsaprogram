
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

int a[1000];
int t1;
int t2;
int n;
int pop1()
{
    if(t1>=1)
    {   t1--;
        return a[t1];
    }
    else
        return -1;
}
int pop2()
{
    if(t2<=n)
    {   t1++;
        return a[t1];
    }
    else
        return -1;
}

void push1(int x)
{
    if(t1<t2-1&&t1<=n)
    {   t1++;
        a[t1]=x;
    }
    else cout<<"stack is full\n";
}

void push2(int x)
{
    if(t1<t2-1&&t2>=1)
    {   t2--;
        a[t2]=x;
    }
    else cout<<"stack is full\n";
}

int main()
{

    le(n);
    t1=0;
    t2=n+1;
    string s1;
    int x;
    while(true)
    {
        cin>>s1;
        if(s1=="ps1")
        {   cin>>x;
            push1(x);
        }

        if(s1=="ps2")
        {   cin>>x;
            push2(x);
        }

         if(s1=="pp1")
        {
            pop1();
        }

        if(s1=="pp2")
        {
            pop2();
        }
        loop(i,1,n+1)
        cout<<a[i]<<" ";
        cout<<"\n";

    }

    return 0;
}

