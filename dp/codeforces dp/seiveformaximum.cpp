
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

int factors[5000001]={};


void seive()
{
    factors[1]=0;
    loop(i,2,3000)
    {
        if(factors[i]==0)
        {  factors[i]=i;
           for(int j=i*i;j<=5000000;j=j+i)
           {
               factors[j]=i;
           }
        }
    }
    loop(i,3000,5000001)
     if(factors[i]==0)
          factors[i]=i;

    loop(i,2,5000001)
    {   //cout<<i<<" "<<i/factors[i]<<" "<<1+factors[i/factors[i]]<<"\n";
        factors[i]=1+factors[i/factors[i]];
        //factors[i]+=factors[i-1];
    }
   // cout<<"1\n";
     loop(i,2,5000001)
    {
       // factors[i]=1+factors[i/factors[i]];
        factors[i]+=factors[i-1];
    }
}

int main()
{
    seive();
    int a,b;
    int ans;
    frmlty
    {
        le2(a,b);
        ans=factors[a]-factors[b];
         printf("%d\n",ans);
    }
    return 0;
}



