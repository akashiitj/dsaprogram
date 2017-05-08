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

string s[1001];

int n,m;
int valid(int i,int j)
{
    if(i>=0&&i<n&&j>=0&&j<m)
        return 1;
    return 0;
}


pii prnt[1000][1000];
pii root(pii obn)//pass objectnumber of object whose root we have to fing
{
    pii i=obn;
    while(prnt[obn.first][obn.second]!=obn)obn=prnt[obn.first][obn.second];
    //obn is now root object no
    while(i!=obn)//doing path compressing
    {
        pii j=prnt[i.first][i.second];
        prnt[i.first][i.second]=obn;
        i=j;
    }
    return obn;
}

void union1(pii i,pii j)
{
    pii x=root(i);
    pii y=root(j);
    //now all those object whose pindex is y we make it x
    prnt[x.first][x.second]=y;
}


int main()
{


    le2(n,m);

    loop(i,0,n)
    cin>>s[i];


    loop(i,0,n)
    {
        loop(j,0,m)
        {
            prnt[i][j]=mp(i,j);
        }
    }


    loop(i,0,n)
    {
        loop(j,0,m)
        {
            if(s[i][j]=='E'&&valid(i,j+1))
                union1(mp(i,j),mp(i,j+1));

            if(s[i][j]=='S'&&valid(i+1,j))
                union1(mp(i,j),mp(i+1,j));

            if(s[i][j]=='W'&&valid(i,j-1))
                union1(mp(i,j),mp(i,j-1));

            if(s[i][j]=='N'&&valid(i-1,j))
                union1(mp(i,j),mp(i-1,j));

        }
    }
    int ans=0;
    loop(i,0,n)
    {
        loop(j,0,m)
        {
            if(prnt[i][j]==mp(i,j))
            ans++;
        }

    }
    cout<<ans<<"\n";



    return 0;
}



