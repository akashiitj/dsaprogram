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
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);
#define led(x) scanf("%lf",&x);

double mini(double a,double b)
{
    return ((a)<(b) ? (a):(b));
}

int m;
int  ni,pn;
double disc;

double bitmask[(1<<15)+1];
double sa[16];
double p[16];
double dis[16][16];

double area(int s)
{
    double a=0.0;
    loop(i,0,m)
    {
        if(s & 1<<i)
            a=a+sa[i];
    }
    return a;
}

double f(int s)
{
    if(s==0)return 0.0;
    if(bitmask[s]!=-1) return bitmask[s];
    double ans=DBL_MAX;
    double ar=area(s);
    loop(i,0,m)
    {
        if(s & 1<<i )
        {
            double di=p[i];
            loop(j,0,m)
            {
                if(s & 1<<j && dis[j][i] !=0 && j!=i)
                {
                    di=di*(1.0-(dis[j][i]/100.0));
                }
            }

            ans=mini(ans,((f(s-(1<<i))*(ar-sa[i]))+di)/ar);


        }
    }
    bitmask[s]=ans;
    return ans;
}

int main()
{


    while(true)
    {
        le(m);
        if(m==0) break;
        loop(i,1,(1<<m)+1)
        bitmask[i]=-1;

        dis[16][16]= {};

        loop(i,0,m)
        {
            led(p[i]);
            led(sa[i]);
            le(ni);
            loop(j,0,ni)
            {
                le(pn);
                led(disc);
                pn--;
                dis[i][pn]=disc;
            }

        }
        double fans=DBL_MAX;

        loop(k,1,1<<m)
        {
            // cout<<f(k)<<" "<<fans<<endl;
            fans=mini(fans,f(k));


        }

        printf("%.4lf\n",fans);
    }
    return 0;
}


