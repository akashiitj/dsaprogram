
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
//cout<<fixed<<setprecision(6)<<ans<<"\n";

int main()
{
    int ex,ey;
    int ax,ay;
    int n;
    char ed,ad;
    double ans;
    frmlty
    {
        le2(ex,ey);
      //  scanf("%c",&ed);
        cin>>ed;
        le(n);
        ans=1000000000;
        cout<<fixed<<setprecision(1);
        loop(i,0,n)
        {
            le2(ax,ay);
            cin>>ad;
            if(ed=='L'||ed=='R')
            {
                if(ad=='L'||ad=='R')
                {
                    if(ay==ey)
                    {
                        if(ax>=ex&&ad=='L'&&ed=='R')
                            ans=miN(ans,double(ax-ex)/2.0);
                        if(ax<=ex&&ad=='R'&&ed=='L')
                            ans=miN(ans,double(ex-ax)/2.0);
                    }
                }
                else
                {
                    if(ed=='R'&&ad=='D'&&ay-ey>=0&&ax>=ex&&ay-ey==ax-ex)
                        ans=miN(ans,ax-ex);
                    if(ed=='R'&&ad=='U'&&ay-ey<=0&&ax>=ex&&ey-ay==ax-ex)
                        ans=miN(ans,ax-ex);
                    if(ed=='L'&&ad=='D'&&ay-ey>=0&&ax<=ex&&ay-ey==ex-ax)
                        ans=miN(ans,ex-ax);
                    if(ed=='L'&&ad=='U'&&ey-ay>=0&&ax<=ex&&ey-ay==ax-ex)
                        ans=miN(ans,ex-ax);
                }
               // cout<<ans<<" 1\n";
            }
            else
            {

                if(ad=='U'||ad=='D')
                {
                    if(ax==ex)
                    {
                        if(ay>=ey&&ad=='D'&&ed=='U')
                            ans=miN(ans,double(ay-ey)/2.0);
                        if(ay<=ey&&ad=='U'&&ed=='D')
                            ans=miN(ans,double(ey-ay)/2.0);
                    }
                }
                else
                {
                    if(ed=='U'&&ad=='L'&&ay-ey>=0&&ax>=ex&&ay-ey==ax-ex)
                        ans=miN(ans,ax-ex);
                    if(ed=='U'&&ad=='R'&&ay-ey>=0&&ax<=ex&&ay-ey==ex-ax)
                        ans=miN(ans,ex-ax);
                    if(ed=='D'&&ad=='R'&&ey-ay>=0&&ax<=ex&&ay-ey==ax-ex)
                        ans=miN(ans,ex-ax);
                    if(ed=='D'&&ad=='L'&&ey-ay>=0&&ax>=ex&&ey-ay==ax-ex)
                        ans=miN(ans,ax-ex);
                }
                //cout<<ans<<" 2\n";
            }
        }
        if(ans==1000000000)printf("SAFE\n");
        else
        cout<<ans<<"\n";
    }
    return 0;
}

