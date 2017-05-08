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

int prime[10001]= {};
int l[10001]= {};
int r[10001]= {};
int k;

int notcnvrt[10001]= {};
int mi[10001];
void seive()
{
    prime[0]=1;
    prime[1]=1;
    loop(i,2,102)
    {
        if(prime[i]==0)
        {
            for(int j=i*i; j<=10000; j=j+i)
                prime[j]=1;
        }
    }
//    loop(i,0,10)
//    cout<<prime[i]<<" ";
//    cout<<"\n";

    int lp=0;
    loop(i,0,10001)
    if(prime[i]==1)r[i]=INT_MAX;
    else l[i]=0;
    loop(i,k,10001)
    {
        if(prime[i]==1)
        {   int j=k;
            int flag=0;
             while((i-j)>=0&&l[i-j]!=0)
             {
               flag=1;
               j=j+k;
             }
             if(flag==1)l[i]=j/k;

        }
    }

    // int lp=0;
//    loop(i,0,10)
//    cout<<l[i]<<" ";
//    cout<<"\n";

    for(int i=10000-k; i>=0; i--)
    {
        if(prime[i]==1)
        {
            if(r[i+k]!=INT_MAX)r[i]=1+r[i+k];
        }
    }
//    loop(i,0,10)
//    cout<<r[i]<<" ";
//    cout<<"\n";
    loop(i,0,10001)
    {
        if(r[i]==INT_MAX)
        {

            notcnvrt[i]=1;

        }
        else
        {
            mi[i]=r[i];

        }
        //  if(i<10)cout<<notcnvrt[i]<<" "<<mi[i]<<endl;
    }
}




int main()
{
    int n;
    le2(n,k);
    int a[n+1][n+1];

    loop(i,1,n+1)
    loop(j,1,n+1)
    le(a[i][j]);

    seive();
    if(n<3)

    {
        cout<<"no\n";
        return 0;
    }
    ll ans=100000000000000;
    ll hv;
    int i1,j1;
    loop(i,2,n)
    loop(j,2,n)
    {
        if(notcnvrt[a[i][j]]||notcnvrt[a[i-1][j-1]]||notcnvrt[a[i-1][j+1]]||notcnvrt[a[i+1][j+1]]||notcnvrt[a[i+1][j-1]])
            continue;
        hv=mi[a[i][j]]+mi[a[i-1][j-1]]+mi[a[i-1][j+1]]+mi[a[i+1][j+1]]+mi[a[i+1][j-1]];

        if(ans>hv)
        {
            ans=hv;
            i1=i;
            j1=j;
        }
    }
    if(ans==100000000000000)
        cout<<"no\n";
    else
    {
        cout<<"yes"<<"\n";
        cout<<ans<<"\n"<<i1<<" "<<j1<<"\n";
    }
    return 0;
}


