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

int prnt[200001];
ll val[200001];

priority_queue<pii,vector<pii >,greater<pii > > mi,dmi;//min priority q

int obnumberofroot(int obn)//pass objectnumber of object whose root we have to fing
{
    int i=obn;
    while(prnt[obn]!=obn)obn=prnt[obn];
    //obn is now root object no
    while(i!=obn)//doing path compressing
    {
        int j=prnt[i];
        prnt[i]=obn;
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
    if(x==y)return;
    prnt[x]=y;
    val[y]+=val[x];

}

int main()
{
    int n,q;
//   cout<<"enter no of objects"<<endl;
    cin>>n>>q;

    loop(i,0,n)
    {
        prnt[i]=i;
        le(val[i]);
        mi.push(mp(val[i],i));
        // if you want to give obnumber you cn give
    }

     int ans=0;
     int n1,n2;
     int tp,prnt1;

    while(q--)
    {
        le2(n1,n2);
        n1--;
        n2--;
        unionbyobnumber(n1,n2);
        //cout<<obnumberofroot(n1)<<" "<<obnumberofroot(n2)<<" "<<val[obnumberofroot(n2)]<<" ou\n";
        while(true)
        {

            tp=mi.top().second;
             prnt1=obnumberofroot(tp);
           if(tp==prnt1&&val[tp]==mi.top().first)
            {
                printf("%d\n",val[tp]);
                break;
            }
            mi.pop();
            mi.push(mp(val[prnt1],prnt1));



        }
        //printf("%d\n",ans);

    }
    return 0;
}




