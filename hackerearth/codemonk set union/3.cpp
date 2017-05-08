
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
struct object
{
    int pindex;//obnumber of parent
    int obnumber;//by default we assume obnumber to be original index no, object number is more appropiate word for obnumber
};

object oa[100001];
int obnumberofroot(int obn)//pass objectnumber of object whose root we have to fing
{   int i=obn;
    while(oa[obn].pindex!=obn)obn=oa[obn].pindex;
    //obn is now root object no
    while(i!=obn)//doing path compressing
    {
        int j=oa[i].pindex;
        oa[i].pindex=obn;
        i=j;
    }
    return obn;
}
int find(int i,int j)
{
    return (obnumberofroot(i)==obnumberofroot(j));
}
void unionbyobnumber(int i,int j)
{
    int x=obnumberofroot( i);
    int y=obnumberofroot( j);
    //now all those object whose pindex is y we make it x
    oa[x].pindex=y;
}
int main()
{
    int n;
   // cout<<"enter no of objects"<<endl;
    cin>>n;

    loop(i,1,n+1)
    {
        oa[i].pindex=i;
        // if you want to give obnumber you cn give
    }
     int q;
     le(q);
     int hv,x,y;
     loop(i,0,q)
     {   le(hv);
         if(hv==1)
         {
             le2(x,y);
             unionbyobnumber(x,y);
         }
         else if(hv==2)
         {
             le(x);
             y=obnumberofroot(x);
             oa[y].pindex=x;
             oa[x].pindex=x;
         }
         else{
            le(x);
            printf("%d\n",obnumberofroot(x));
         }
     }



    return 0;
}


