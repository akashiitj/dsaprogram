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
    string s,s1,sd;
    getline(cin,s);
    cin>>s1;
    sd=s1;

    int x=s1.length();
    int y=x;
    while(x<s.length())
    {
        s1=s1+sd;
        x=x+y;
    }
    int n=s.length();
    int hv;
    char c1;
    loop(i,0,n)
    {
        if(s[i]>='a'&&s[i]<='z' )
        {
          if(s1[i]>='a')
           {

                hv=(int)(s1[i]-'a');
                if(-hv+s[i]<'a')
                        c1=char(-hv+s[i]+'z'-'a'+1);
                else c1=char(-hv+s[i]);
                s[i]=c1;
           }
           else {

                hv=(int)(s1[i]-'A');
                if(s[i]-hv<'a')
                        c1=char(-hv+s[i]+'z'-'a'+1);
                else c1=char(-hv+s[i]);
                s[i]=c1;
           }
        }

        if(s[i]>='A'&&s[i]<='Z' )
        {
           if(s1[i]>='a')
           {

                hv=(int)(s1[i]-'a');
                if(-hv+s[i]<'A')
                        c1=char(-hv+s[i]+'Z'-'A'+1);
                else c1=char(-hv+s[i]);
                s[i]=c1;
           }
           else {

                hv=(int)(s1[i]-'A');

                if(s[i]-hv<'A')
                        c1=char(-hv+s[i]+'Z'-'A'+1);
                else c1=char(-hv+s[i]);

                s[i]=c1;


           }
        }

    }
    cout<<s<<"\n";
    return 0;
}


