#include <bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
using namespace std;
int main()
{
    ll t,w,b;
    cin>>t>>w>>b;
    ll temp = min(w,b)-1;
    if(t<=temp)
    {
        printf("1/1\n");
        return 0;
    }
    ll res = temp;
    double lcm = (double)((double)w*double(b))/__gcd(w,b);
    if(lcm<=t)
    {
        ll q = t/(ll)(lcm);
        ll r = t%(ll)(lcm);
        res = res + q + ((q>0)?((q-1)*(temp)):0) + min(r,temp);
    }
    ll g = __gcd(res,t);
    res = res/g;
    t = t/g;
    printf("%lld/%lld\n",res,t);
    return 0;
}
