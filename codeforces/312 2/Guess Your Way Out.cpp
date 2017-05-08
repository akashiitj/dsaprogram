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

#define F first;
#define S second;

//cout<<fixed<<setprecision(6)<<ans<<"\n";
ll h;
ll leftl(ll i,ll nn)
{
    return nn*1<<(h-i);
}

ll rightl(ll i,ll nn)
{
    loop(i1,i,h)
    nn=(nn*2)+1;
    return nn;
}


vector<ll> has;
vector<int> nums;
map<ll,int> m;
int main()
{
    map<ll,int>::iterator it;
    ll i,l,r,ans;
    int q;
    lell(h);
    le(q);
    if (q==0)
    {
        if (h==1) printf("1\n");
        else printf("Data not sufficient!\n");
        return 0;
    }
    loop(i1,0,q)
    {
        le2ll(i,l);
        le2ll(r,ans);
        if(ans==1)
        {
            m[leftl(i,l)]++;
            m[rightl(i,r)+1]--;
        }
        if(ans==0)
        {
            m[leftl(1,1)]++;
            m[leftl(i,l)]--;
            m[rightl(i,r)+1]++;
            m[rightl(1,1)+1]--;
        }

    }

    loop(i,1,nums.size())
    {
        nums[i]+=nums[i-1];
    }
    int found=0,place;
    loop(i,0,nums.size())
    if(nums[i]==q)found++,place=i;


        if (found>1) printf("Data not sufficient!\n");
        else if(found==1)
        {
            if (has[place]==rightl(1,1) || m.count(has[place]+1)) printf("%I64d\n",has[place]);//has[where]+1 is present it means has[where] is unique
            else printf("Data not sufficient!\n");
        }
        else printf("Game cheated!\n");
    return 0;
}


