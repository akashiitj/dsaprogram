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


int ht[1000001]={};


struct compare
{
  bool operator()(const int& l, const int& r)
  {
      return l > r;
  }
};




int main()
{
    priority_queue<int,vector<int>, compare > mi;
    priority_queue <int> ma;
    int q,hv,x,hvma;
    le(q);
    loop(i,0,q)
    {
        le(hv);
        if(hv==1)
        {
            le(x);
            ht[x]++;
            mi.push(x);
            ma.push(x);
        }

       else if(hv==2)
        {
            le(x);
            if(ht[x]>=1)ht[x]--;
            else printf("-1\n");
        }

       else if(hv==3)
        {
            hvma=ma.top();
            while(ht[hvma]==0&&ma.size()!=0)
             {

                ma.pop();
                hvma=ma.top();

            }
            if(ma.size()==0)
                printf("-1\n");
            else printf("%d\n",hvma);
        }
       else if(hv==4)
        {
            hvma=mi.top();
            while(ht[hvma]==0&&mi.size()!=0)
             {

                mi.pop();
                hvma=mi.top();

            }
            if(mi.size()==0)
                printf("-1\n");
            else printf("%d\n",hvma);
        }


    }
    return 0;
}

