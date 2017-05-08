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

int a[10001]= {};
int prime[10001]= {};
int dp[10001];

int mod1(int x)
{
    return x;
}

int fast_mul(int A,int pow)
{
    int C=1;


    while(pow>0)
    {
        if(pow&1)
        {
            C=mod1(C)*mod1(A);
            C=mod1(C);
            // cout<<C<<" "<<mod1(A)<<endl;
        }
        A=mod1(mod1(A)*mod1(A));
        pow>>=1;
    }
    return mod1(C);
}

void precal()
{
    prime[0]=1;
    prime[1]=1;
    loop(i,2,102)
    {
        if(prime[i]==0)
        {
            a[i]=1;
            for(int j=i*i; j<=10000; j=j+i)
                prime[j]=1;
        }
    }
    loop(i,1,10)
    {
        int n11=fast_mul(i,i);//first you do i*i here bigmistake
        if(prime[i]==0&&n11<=10000)
            a[n11]=1;
    }

    loop(i,2,10001)
    if(prime[i]==0)a[i]=1;//forgot this also


    loop(i,2,10001)
    {
        if(a[i]==1)
        {
            //a[i]=1;
            continue;

        }
        a[i]=INT_MAX;
        loop(j,2,i/2+1)
        a[i]=miN(a[i],a[j]+a[i-j]);
    }

}

int main()
{
    int n;
    precal();
    frmlty
    {
        le(n);
        printf("%d\n",a[n]);
    }
    return 0;
}


