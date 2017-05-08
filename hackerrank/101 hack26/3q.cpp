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

#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);


int main()
{
    int n1,n2;
    string s1,s2,s="";
    frmlty
    {   s="";
        cin>>s1>>s2;
        n1=s1.length();
        n2=s2.length();
        loop(i,0,abs(n1-n2))
        {
            s=s+'0';
        }
        if(n1>n2)s2=s+s2;
        if(n2>n1)s1=s+s1;
       // cout<<s1<<" "<<s2<<endl;
        loop(i,0,max(n1,n2))
        {   //cout<<s1[i]+s2[i]-'0'-'0'<<endl;
            if(s1[i]+s2[i]-'0'-'0'>9)
            {
                loop(j,i,max(n1,n2))
                s1[j]=9+'0';
                break;
            }
            else s1[i]=s1[i]+s2[i]-'0';
        }
        cout<<s1<<"\n";

    }
    return 0;
}

