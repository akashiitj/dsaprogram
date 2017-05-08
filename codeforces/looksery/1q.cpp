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



int main()
{
    int x,y;
    le2(x,y);
    char c[x][y];
    loop(i,0,x)
    loop(j,0,y)
    cin>>c[i][j];
    int ans=0;
    loop(i,0,x-1)
    {
        int f,a,c1,e;
        loop(j,0,y-1)
        {   f=0;
        a=0;
        c1=0;
        e=0;
            loop(k,i,i+2)
            loop(l,j,j+2)
            {
                if(c[k][l]=='f')f=1;
                if(c[k][l]=='a')a=1;
                if(c[k][l]=='c')c1=1;
                if(c[k][l]=='e')e=1;
            }
            if(f&&a&&c1&&e)ans++;
        }
    }
    cout<<ans<<"\n";

    return 0;
}


