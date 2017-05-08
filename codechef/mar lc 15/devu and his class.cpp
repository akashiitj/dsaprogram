#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

#define fast      ios_base::sync_with_stdio(false)
#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
//#define vs        vector<string>
#define vll       vector<ll>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair



#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define mod       1000000007

string s;
int bc;
int gc;
int l;
int  f(int type)
{
    int l =s.length();
    bc=0;
    gc=0;
    vi b,g;
    int val1,val,val2;
    loop(i,0,l)
    {
        if(s[i]=='B')bc++;
        else gc++;
    }
    if(abs(bc-gc)>1)return -1;
    else if(bc==gc)
    {
        char t1='B',t2='G';
        loop(i,0,l)
        {
            if(s[i]!=t1)
            {
                if(s[i]=='B')
                    b.pb(i);
                else g.pb(i);
            }
            swap(t1,t2);
        }
        val1=0;
        if(type==0)val1=b.size();
        else
        {
            loop(i,0,b.size())
            {
                val1=val1+abs(b[i]-g[i]);
            }
        }
        b.clear();
        g.clear();
        t1='G';
        t2='B';
        loop(i,0,l)
        {
            if(s[i]!=t1)
            {
                if(s[i]=='B')
                    b.pb(i);
                else g.pb(i);
            }
            swap(t1,t2);
        }
        val2=0;
        if(type==0)val2=b.size();
        else
        {
            loop(i,0,b.size())
            {
                val2=val2+abs(b[i]-g[i]);
            }
        }
        return min(val1,val2);
    }
    else if(bc>gc)
    {
        char t1='B',t2='G';
        loop(i,0,l)
        {
            if(s[i]!=t1)
            {
                if(s[i]=='B')
                    b.pb(i);
                else g.pb(i);
            }
            swap(t1,t2);
        }
        val1=0;
        if(type==0)val1=b.size();
        else
        {
            loop(i,0,b.size())
            {
                val1=val1+abs(b[i]-g[i]);
            }
        }
        return val1;
    }
    else
    {
        char t1='G',t2='B';
        loop(i,0,l)
        {
            if(s[i]!=t1)
            {
                if(s[i]=='B')
                    b.pb(i);
                else g.pb(i);
            }
            swap(t1,t2);
        }
        val2=0;
        if(type==0)val2=b.size();
        else
        {
            loop(i,0,b.size())
            {
                val2=val2+abs(b[i]-g[i]);
            }
        }
        return val2;
    }
}
int main()
{
    fast;
    int type;
    frmlty
    {
        cin>>type;
        cin>>s;
        cout<<f(type)<<endl;
    }
    return 0;
}
