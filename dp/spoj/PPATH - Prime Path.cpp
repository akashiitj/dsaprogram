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

int isp[10001];

void sv()
{
    for(int i=2; i<=10000; i++)
    {
        if(isp[i]==0)
        {
            for(int j=i*i; j<=10000; j=j+i)
                isp[j]=1;
        }
    }
}

int x,y;
int dist[10001];

int bfs()
{
    queue<int > q;
    int dist[10001];
    loop(i,0,10001)
    dist[i]=-1;


    q.push(x);
    dist[x]=0;
    int d=0;
    int sv;

    char s[4];
    while(true)
    {
        sv=q.front();
        q.pop();
        d=sv;
        if(y==sv)
        {
            return dist[sv];
        }

        loop(i,0,4)
        {
            sprintf(s,"%d",d);
            loop(j,0,10)
            {   if(i==0&&j==0)continue;
                s[i]=j+'0';
                int nn=atoi(s);
             //   cout<<nn<<" "<<sv<<"\n";
                if(dist[nn]==-1&&isp[nn]==0)
                {
                    dist[nn]=1+dist[sv];
                    q.push(nn);
                }
            }

        }


    }
}


int main()
{  sv();

    frmlty
    {
        le2(x,y);
        cout<<bfs()<<"\n";

    }
    return 0;
}
