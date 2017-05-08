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

ll contbits(ll n)
{
    ll ans=0;
    while(n!=0)
    {
        if(n%2==1)ans++;
        n=n/2;
    }
    return ans;

}

ll nc3(ll n)
{
    if(n<3)return 0;
    return (n*(n-1)*(n-2))/6;
}

int main()
{
    int n;
    ll x;
    le(n);
    ll mask[16]= {};//keep count of mask ifelement contan 2, 3   mask[3]++;  11 mask
    int a[10];
    loop(i,0,10)
    a[i]=-1;
    a[2]=0;
    a[3]=1;
    a[5]=2;
    a[7]=3;
    ll cur_dgt;
    int cur_mask;
    loop(i,0,n)
    {
        cur_mask=0;
        lell(x);
        while(x!=0)
        {
            cur_dgt=x%10;
            x=x/10;
            if(a[cur_dgt]!=-1)cur_mask=cur_mask|(ll)pow(2,a[cur_dgt]);

        }
        mask[cur_mask]++;

    }
    ll hv;
    ll ans=0;
    loop(i,1,16)
    {
        hv=0;
        loop(j,i,16)//finding number of element that contain elements represented by mask i
        {
            if((i&j)==i)
                hv=hv+mask[j];
        }
        if(contbits(i)%2==1)// inclusion
        {
            ans=ans+nc3(hv);
        }
        else ans=ans-nc3(hv);//exclusion

    }
    cout<<ans<"\n";
    return 0;
}

