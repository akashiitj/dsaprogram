

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

int cl(int n)
{
    if(n%2==0)return n/2;
    else return(n/2)+1;
}

 int l[5001];
    int r[10010];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int ht[5001]= {};
    int n,x;
    //cout<< ht[4993]<<"\n";
    le(n);
    loop(i,0,n)
    {
        le(x);
        ht[x]++;
    }
    int i1,j1;
    loop(i,1,5001)
    if(ht[i]!=0)
    {

        i1=i;
        break;
    }
    loop(i,1,5001)
    if(ht[5001-i]!=0)
    {

        j1=5001-i;
        break;
    }

    l[0]=0;
    loop(i,1,5001)
    l[i]=l[i-1]+ht[i];

    r[5001]=0;
    for(int i=5000;i>=0;i--)
    r[i]=r[i+1]+ht[i];

    int ans=500000;

//    loop(i,0,10)
//    cout<<i<<" "<<l[i]<<" "<<r[i]<<"\n";
//    cout<<endl;

    loop(i,i1,j1+1)
    {
       if(ht[i]!=0) ans=min(ans,r[(2*i)+1]+l[i-1]);
    }
    cout<<ans<<"\n";

    return 0;
}


