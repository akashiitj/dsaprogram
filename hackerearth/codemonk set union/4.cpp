

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
    int siz;//by default we assume obnumber to be original index no, object number is more appropiate word for obnumber
};

object oa[100001];
int ht[100001]= {};
int obnumberofroot(int obn)//pass objectnumber of object whose root we have to fing
{
    int i=obn;
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
int ma=1;
void unionbyobnumber(int i,int j)
{
    int x=obnumberofroot( i);
    int y=obnumberofroot( j);
    //now all those object whose pindex is y we make it x
    if(x!=y)
    {
        ht[oa[x].siz]--;
        ht[oa[y].siz]--;
        ht[oa[x].siz+oa[y].siz]++;
        if(oa[x].siz+oa[y].siz>ma)
            ma=oa[x].siz+oa[y].siz;
        oa[y].pindex=x;
        oa[x].siz+=oa[y].siz;
    }
}
int main()
{
    int n;
    // cout<<"enter no of objects"<<endl;
    cin>>n;

    loop(i,1,n+1)
    {
        oa[i].pindex=i;
        oa[i].siz=1;

        // if you want to give obnumber you cn give
    }
    int q;
    le(q);
    ht[1]=n;
    int hv,x,y;
    int si=1;
    int li=1;
    int mi=INT_MAX;
    int ki,j;
    loop(i,0,q)
    {
        le2(x,y);
        unionbyobnumber(x,y);
        mi=INT_MAX;
        while(ht[si]==0)
        {
            si++;
        }
        // cout<<ma<<" "<<si<<"\n";
        if(si==ma)
            printf("0\n");
        else
        {
            int flag=0;
            j=si;

            while( j<=ma-1 )
            {
                ki=j+1;
                if(ht[j]>1)
                {
                    flag=1;
                    printf("0\n");
                    break;
                }
                else
                {
                    while(ht[ki]==0)
                        ki++;
                    mi=miN(mi,ki-j);
                }
                j=ki;
            }
            if(flag==0)        printf("%d\n",mi);
        }
    }



    return 0;
}


