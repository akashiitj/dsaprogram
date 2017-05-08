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

bool ArePair(char opening,char closing)
{
    if(opening == '(' && closing == ')') return true;

    return false;
}
bool AreParanthesesBalanced(string exp)
{
    stack<char>  S;
    for(int i =0; i<exp.length(); i++)
    {
        if(exp[i] == '(' )
            S.push(exp[i]);
        else if(exp[i] == ')')
        {
            if(S.empty() || !ArePair(S.top(),exp[i]))
                return false;
            else
                S.pop();
        }
    }
    return S.empty() ? true:false;
}



int main()
{
    string s;
    int n,k;
    vector<string> vs1,vs2;
    frmlty
    {
        cin>>s;
        le(k);
        n=s.length();
        if(AreParanthesesBalanced(s))
        {
            if(k>2)
                cout<<-1<<"\n";
            else
            {
                int i1,i2;
                loop(i,0,n)
                {
                    if(s[i]=='(')
                        i1=i;
                    if(s[i]==')')
                    i2=i;
                }
                string s1[2];
                s1[0]=s.substr(0,i1)+s.substr(i1+1);
                 s1[1]=s.substr(0,i2)+s.substr(i2+1);
                sort(s1,s1+2);
                if(k==1)cout<<s1[0]<<"\n";
                else cout<<s1[1]<<"\n";
            }
        }
        else{

            if(k>1)cout<<-1<<"\n";
            else cout<<s<<"\n";
        }
    }
    return 0;
}


