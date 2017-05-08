
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
    int l;
    int s,s1;
    le2(l,s);
    s1=s;
    if(s>l*9||s<1)
    {
        if(l==1&&s==0)cout<<"0 0\n";//you missed it
        else cout<<"-1 -1\n";
        return 0;
    }
    string ma="",mi="";
    loop(i,0,l)
    {
        mi=mi+'0';
        if(s>=9)
        {
            ma=ma+'9';
            s=s-9;
        }
        else
        {
            char hv='0'+s;
            ma=ma+hv;
            s=0;
        }
    }
    int mustrem;
    mi[0]='1';
    s1=s1-1;
    for(int i=l-1; i>=1; i--)
    {
        if(s1>=9)
        {
            mi[i]='9';
            s1=s1-9;
        }
        else
        {
            mi[i]=s1+'0';
            s1=0;
        }

    }
    //cout<<s1<<"\n";
    mi[0]=s1+'1';
    cout<<mi<<" "<<ma<<"\n";
    return 0;
}


