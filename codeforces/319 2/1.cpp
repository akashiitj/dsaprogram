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

int isp[1001];
vi p;
vi ans1;

int h[1001][1001];
int ans[1001];
int main()
{
    int n;
    le(n);

    if(n==1)
    {

        cout<<"0\n";
        return 0;
    }


    for(int i=2; i<=n; i++)
    {
        int pf=0;
        int id=i;
        int flag=0;
        int ans=1;
        while(id%2==0)
        {
            id=id/2;
            ans=ans*2;
            flag=1;

        }

        if(flag==1)
            pf++;
        for(int j=3; j<=id; j=j+2)
        {
            int flag=0;
            while(id%j==0)
            {
                id=id/j;
                flag=1;

            }
            if(flag==1)
                pf++;
        }
        if(id>1)
            pf++;

        //cout<<isp[i]<<" "<<pf<<" "<<i<<"\n";
        if(isp[i]==0)
            ans1.pb(i);

        else  if(pf>=2)
            if(n>=i*2)
               {

                ans1.pb(i);//
           } else  if(pf<2)
                ans1.pb(i);//


    }

    cout<<ans1.size()<<"\n";
    loop(i,0,ans1.size())
    cout<<ans1[i]<<" ";
    cout<<"\n";


    return 0;
}
