
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


#define F first
#define S second

int main()
{
    string s,s1="";
    cin>>s;
    int n=s.length();
    vs v;
    loop(i,0,n)
    s1=s1+'0';
   // cout<<s1<<"\n";
    int x=0;
    string ans;
   // cout<<(char)s[0]-'1'<<" df\n";
    while(s!=s1)
    {   x=0;
        while(s[x]=='0')x++;
        ans="";
        loop(i,x,n)
        {
            if(s[i]>'0'){
                ans=ans+'1';
                char c=s[i]-'1';
                c=c+'0';
                s[i]=c;
       //         cout<<s<<" "<<c<<" f\n";
            }
            else ans=ans+"0";
        }
     //   cout<<s<<" s\n";
        v.pb(ans);
       // break;
    }
    cout<<v.size()<<"\n";
    loop(i,0,v.size())
    cout<<v[i]<<" ";

    cout<<"\n";

    return 0;
}



