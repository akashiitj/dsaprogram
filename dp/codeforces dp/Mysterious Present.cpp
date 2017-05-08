

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

pair<pair<int,int>,int > a[5001];
int dp[5001]= {};
int trace[5001]= {};

int main()
{
    int n,w,h,w1,h1;
    le2(n,w);
    le(h);
    loop(i,1,n+1)
    {
        le2(w1,h1);
        a[i].first.first=w1;
        a[i].first.second=h1;
        a[i].second=i;
    }
    sort(a+1,a+1+n);



    int si=0;;
    loop(i,1,n+1)
    {
        if( a[i].first.first>w&&a[i].first.second>h)
        {
            si=i;
            break;
        }
    }
    if(si==0)
    {
        cout<<"0\n";
        return 0;
    }
    int ans=0;
    int ansi;
    loop(i,si,n+1)
    {
        dp[i]=1;
        trace[i]=i;
        loop(j,si,i)
        {
            if(a[i].first.first>a[j].first.first&&a[i].first.second>a[j].first.second)
            {
                if(dp[j]+1>dp[i])
                {
                    dp[i]=maX(dp[i],dp[j]+1);
                    trace[i]=j;

                }

            }

        }
        if(dp[i]>ans)
        {
            ans=dp[i];
            ansi=i;
        }
        // cout<<i<<" "<<trace[i]<<endl;

    }
    cout<<ans<<"\n";
    if(ans!=0)
    {
        vi v;
        v.pb(ansi);
        while(trace[ansi]!=ansi)
        {
            v.pb(trace[ansi]);
            ansi=trace[ansi];
        }



        //  sort(v.begin(),v.end());
        loop(i,0,v.size())
        cout<<a[v[v.size()-i-1]].second<<" ";
        cout<<"\n";
    }


    return 0;
}


