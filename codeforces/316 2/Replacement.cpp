
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

int main()
{   int n,m;
    le2(n,m);
    string s;
    cin>>s;

    int ans=0;
    int ta;
    loop(i,0,n)
    {   ta=0;
        if(s[i]=='.')
        {  ta=0;
            while(s[i]=='.')
            {
                ta++;
                i++;
            }
            ans=ans+ta-1;
        }
    }
    //cout<<ans<<"\n";
    char ch;
    loop(i,0,m)
    {
        le(ta);
        cin>>ch;


        if(ch=='.'&&ch!=s[ta-1])
        {
            s[ta-1]='.';
            if(ta==1&&n>1&&s[ta]=='.')
            ans++;

            else if(ta==n&&n>1&&s[ta-2]=='.')
                ans++;

            else if(n>1)
            {
                if(s[ta-2]=='.'&&s[ta]=='.')
                    ans=ans+2;
               else if(s[ta-2]=='.'||s[ta]=='.')
                ans++;
            }

        }
        if(ch!='.'&&'.'==s[ta-1])
        {
            s[ta-1]=ch;
            if(ta==1&&n>1&&s[ta]=='.')
            ans--;

            else if(ta==n&&n>1&&s[ta-2]=='.')
                ans--;

            else if(n>1)
            {
                if(s[ta-2]=='.'&&s[ta]=='.')
                    ans=ans-2;
               else if(s[ta-2]=='.'||s[ta]=='.')
                ans--;
            }






        }
        printf("%d\n",ans);
    }
    return 0;
}


