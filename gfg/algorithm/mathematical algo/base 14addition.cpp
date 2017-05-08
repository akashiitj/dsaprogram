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
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

#define F first
#define S second

int nv(char c)// characcter to number '1'-->1  A-->10  C-->13
{
    if(c<=57)return c-48;
    return c-'A'+10;
}

char cv(int n)//1-->'1' 10-->'A'
{
    if(n<=9)return n+'0';
    return n-10+'A';
}

string f(string a,string b,int n1)
{
    int curs;
    int carry=0;
    for(int i=n1-1; i>=0; i--)
    {
        curs=nv(a[i])+nv(b[i])+carry;
        carry=curs/14;
        a[i]=cv(curs%14);
    }
    return a;
}

int main()
{
    string a,b;
    cin>>a>>b;
    int n1=a.length();
    int n2=b.length();
    int d=abs(n1-n2);
    if(d!=0)
    {
        if(n1<n2)
            loop(i,0,d)
            a='0'+a;
        else
            loop(i,0,d)
            b='0'+b;

    }
    a='0'+a;
    b='0'+b;
    cout<<a<<" "<<b<<" "<<n1<<"\n";
    cout<<f(a,b,n1);
    return 0;
}

