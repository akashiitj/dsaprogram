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

int h[100001];
int a[100001];
int pr[100001];

int main()
{
    int n;
    le(n);
    loop(i,1,n+1)
    le(h[i]);

    a[1]=0;
    pr[1]=-1;
    loop(i,2,n+1)
    {
        a[i]=1;
        int flag=0;
        pr[i]=i-1;
        for(int j=i-1; j>=1; j=pr[j])//j th is grater than i so searchung for smaller than i in element smaller than j
            //pr[j] means first element smaller than h[j] from back side and and between j and pr[j] all will die including j
            //otherwiae pr[j] is first element which is not going to die
        {

            if(h[j]<h[i])//we found element smaller than i between them all are died suppose jth one is died already it means smaller than jth is there so i ko vo maar dega
            {
                flag=1;
                break;
            }
            if(a[j]==0)//jth is not going to die so ith also is not going to die
                break;
            a[i]=max(a[i],a[j]+1);//jab bech ke die honge tabhi ith die hoga 1 din baad
            pr[i]=pr[j];//jth mar gaya hai and its time is counted by ith so in futher from this i we directly junp further
        }
        if(flag==0)
            a[i]=0;
        // cout<<a[i]<<" ";
    }

    cout<<*max_element(a+1,a+1+n);

    return 0;
}

