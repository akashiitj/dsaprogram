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

 int visa[8];
  int visb[8];
int main()
{
    string s[8];
    int ma=10;
    int mb=10;

    loop(i,0,8)
    {
        cin>>s[i];
        loop(j,0,8)
        {   if(s[i][j]=='B')
            visa[j]=1;
            if(s[i][j]=='W'&&visa[j]==0)
                ma=min(ma,i-0);


        }

    }
   for(int i=7;i>=0;i--)
    {

        loop(j,0,8)
        {   if(s[i][j]=='W')
            visb[j]=1;
            if(s[i][j]=='B'&&visb[j]==0)
                mb=min(mb,7-i);


        }

    }

    //cout<<ma<<" "<<mb<<"\n";
    if(ma<=mb)
        cout<<"A\n";
    else cout<<"B\n";
    return 0;
}


