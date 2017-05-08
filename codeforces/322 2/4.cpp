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

int ispersq(int  n)
{
    int i = 1;
    while(n>0)
    {
        n = n - i ;
        i = i + 2;
    }
    if(n==0) return 1;
    else return 0;
}

pair<pii,int> a[3];

int main()
{
    int x1,y1,x2,y2,x3,y3;
    le2(x1,y1);
    le2(x2,y2);
    le2(x3,y3);

    if(x1>=y1)
        a[0]=mp(mp(x1,y1),0);
    else a[0]=mp(mp(x1,y1),0);

    if(x2>=y2)
        a[1]=mp(mp(x2,y2),1);
    else a[1]=mp(mp(y2,x2),1);

    if(x3>=y3)
        a[2]=mp(mp(x3,y3),2);
    else a[2]=mp(mp(y3,x3),2);

    int ta=x1*y1+x2*y2+x3*y3;

    if(ispersq(ta)==0)
    {
        cout<<"-1\n";
    }
    else
    {
        int sq=sqrt(ta);
        int mx=maX(x1,y1);
        mx=maX(x2,y2);
        mx=maX(x3,y3);

        sort(a,a+3);
        reverse(a,a+3);

        if(mx>sq)
        {
            cout<<"-1\n";
            return 0;
        }

        int rem=sq-a[0].first;
        int sr;
        if(rem==0)
        {
            sr=sq-a[0].second;
            if(a[1].first==sq)
            {
                if(a[2].first!=sq)
                {
                    cout<<"-1";
                    return 0;
                }
                else if(a[1].second+a[2].second!=rem)
                {

                    cout<<"-1";
                    return 0;

                }
                else{
                    cout<<sq<<"\n";

                    loop(i,0,sq)
                    {
                        loop(j,0,a[0].second)
                        cout<<char(a[0].second+'A');
                    }

                    loop(i,0,sq)
                    {
                        loop(j,0+a[0].first.second,a[1].second)
                        cout<<char(a[1].second+'A');
                    }

                    loop(i,0,sq)
                    {
                        loop(j,0+a[0].first.second+a[1].first.second,a[2].second)
                        cout<<char(a[2].second+'A');
                    }

                }

            }
        }





    }

    return 0;
}



