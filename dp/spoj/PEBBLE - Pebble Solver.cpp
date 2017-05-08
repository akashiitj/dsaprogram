
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
    string s;
    int s1=0;
    while(cin>>s)
    {   s1++;
        int ans=0;
        int flag=0;
        reverse(s.begin(),s.end());
        int i1=0;
        while(i1<s.length()&&s[i1]=='1')
        {

            i1++;
        }
       // cout<<i1<<" "<<s.length()<<"\n";
        if(i1>0)ans++;
        while(i1<s.length())
        {  // cout<<i1<<"\n";
            while(i1<s.length()&&s[i1]=='0')
                i1++;
            int flag=0;
            while(i1<s.length()&&s[i1]=='1')
            {
                flag=1;
                i1++;
            }
            if(flag==1)ans+=2;
            //cout<<ans<<"\n";
        }
        cout << "Game #"<<s1<<": "<<ans<<endl;
       // cout<<ans<<"\n";
    }

    return 0;
}

