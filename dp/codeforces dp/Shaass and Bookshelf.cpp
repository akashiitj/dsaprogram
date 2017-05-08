
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

int main()
{
    int n;
    le(n);
    vi wt1;
    vi wt2;
    int w,t;
    wt1.pb(0);
    wt2.pb(0);
    loop(i,0,n)
    {
        le2(t,w);
        if(t==1)wt1.pb(w);
        else wt2.pb(w);
    }
    sort(wt1.begin(),wt1.end());
    sort(wt2.begin(),wt2.end());
    loop(i,1,wt1.size())
    wt1[i]+=wt1[i-1];

    loop(i,1,wt2.size())
    wt2[i]+=wt2[i-1];

    int ans=1000;
    int cw=0;
    //int  tw=wt1.size()-1+(wt2.size()-1)*2;
    // cout<<tw<<"\n";
    int t1=wt1.size()-1,t2=wt2.size()-1;

//     loop(i,1,wt1.size())
//     cout<<wt1[i]<<" ";
//     cout<<"\n";
//
//    loop(i,1,wt2.size())
//    cout<<wt2[i]<<" ";
//     cout<<"\n";

    loop(i,0,wt1.size())
    {
        cw=wt1[i];
      //  cout<<cw<<" "<<i<<" i\n";
        loop(j,0,wt2.size())
        {   cw=wt1[i];
            cw+=wt2[j];
               // cout<<cw<<" "<<j<<" j\n";
            if(cw<=(t1-i+(t2-j)*2))
            {
                if(ans>(t1-i+(t2-j)*2))
                {
                    ans=miN(ans,t1-i+(t2-j)*2);
        //            cout<<ans<<" "<<i<<" "<<j<<"\n";
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}


