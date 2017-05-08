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


int main()
{
    int a,b;
    int tc=0;
    while(true)
    {
        tc++;
        map<int,int> m;
        map<int,int> ::iterator it;
        cout<<m[4]<<"\n";
        le2(a,b);

        if(a==0&&b==0)return 0;
        int c=0;
        while(a%2==0)
        {
            a=a/2;
            c++;
        }
        if(c!=0)m[2]=c;
        for(int i=3; i*i<=a; i=i+2)
        {
            c=0;
            while(a%i==0)
            {
                a=a/i;
                c++;
            }
            if(c!=0)m[i]=c;
        }
        if(a>2)m[a]=1;
        int ans=0;
        c=0;
        while(b%2==0)
        {
            b=b/2;
            c++;
        }
        if(c!=0&&m.find(2)!=m.end())
        {
            m[2]=abs(m[2]-c);
            // ans+=m[2];
        }
        if(c!=0&&m.find(2)==m.end())
        {
            m[2]=abs(c);
            //  ans+=m[2];

        }
        for(int i=3; i*i<=b; i=i+2)
        {
            c=0;
            while(b%i==0)
            {
                b=b/i;
                c++;
            }
            if(c!=0&&m.find(i)!=m.end())
            {
                m[i]=abs(m[i]-c);
                //ans+=m[i];
            }
            if(c!=0&&m.find(i)==m.end())
            {
                m[i]=abs(c);
                //ans+=m[i];

            }
        }
        if(b>2&&m.find(b)!=m.end())
        {
            m[b]=abs(m[b]-1);
            //ans+=m[i];
        }
        if(b>2&&m.find(b)==m.end())
        {
            m[b]=abs(1);
            //ans+=m[i];

        }
        c=0;
        for(it=m.begin(); it!=m.end(); ++it)
        {
            ans=ans+it->second;
            c++;
        }
        cout<<tc<<". "<<c<<":"<<ans<<"\n";
    }
    return 0;
}

