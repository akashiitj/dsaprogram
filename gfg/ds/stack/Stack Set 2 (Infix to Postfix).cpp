
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

vector<char> v;
vector<char> stck;

int isoperand(char c)
{
    if(c>='a'&&c<='z'||c>='A'&&c<='Z')
        return 1;
    else return 0;

}

int isoperator(char c)
{
    if(c=='*'&&c=='/'||c>='-'||c=='+')
        return 1;
    else return 0;

}

int precedence(char c)
{
    if(c=='+'||c=='-')
        return 1;
    if(c=='/'||c=='*')
        return 2;
    if(c=='^')
        return 3;
    return -1;//for (



}

void postfix(string s)
{   v.clear();
stck.clear();
    int n=s.length();
    loop(i,0,n)
    {
        if(isoperand(s[i]))
            stck.pb(s[i]);
        else if(s[i]=='(')
            v.pb(s[i]);
        else if(s[i]==')')
        {
            while(v.size()!=0&&v.back()!='(')//you made mistake here v[i]
            {
                stck.pb(v.back());
                v.pop_back();
            }
            v.pop_back();
        }
        else
        {
            while(v.size()!=0&&precedence(s[i])<=precedence(v.back()))
            {
                stck.pb(v.back());
                v.pop_back();
            }

            v.pb(s[i]);
        }


    }
    while(v.size()!=0)
    {
        stck.pb(v.back());
        v.pop_back();
    }
    loop(i,0,stck.size())
    cout<<stck[i];
    cout<<"\n";
}

vector<int > reslt;

int result()
{
    loop(i,0,stck.size())
    {
        if(isoperand(stck[i]))
        {
            reslt.pb(stck[i]);
        }
        else
        {
            int e2=reslt.back();
            reslt.pop_back();
            int e1=reslt.back();
            reslt.pop_back();

            if(stck[i]=='+')
            {
                reslt.pb(e1+e2);
            }
            if(stck[i]=='-')
            {
                reslt.pb(e1-e2);
            }
            if(stck[i]=='*')
            {
                reslt.pb(e1*e2);
            }
            if(stck[i]=='/')
            {
                reslt.pb(e1/e2);
            }
        }
    }
    return reslt[0];
}

int main()
{
    string s;
    frmlty{
    cin>>s;
    postfix(s);
    }

    //cout<<result();
    return 0;
}

