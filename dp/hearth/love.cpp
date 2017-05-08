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

ll dp[1<<17];

int count1(int n)
{
    int ans=0;
    loop(i,0,18)
    if(n & 1<<i )ans++;
    return ans;
}

int main()
{
    int n;
    le(n);
    ll l[n];
    ll d[n];
    int tlv=0;
    loop(i,0,n)
    {

        lell(l[i]);

    }
    loop(i,0,n)
    lell(d[i]);
    dp[0]=0;
    int tset=(1<<n)-1;
    // cout<<tset<<"\n";
    int bestlvforset;
    int ans=0;
    int c1;
    int ci;
    ll hv1,hv2;
    loop(i,1,tset+1)
    {
        c1=count1(i);
       // cout<<i<<" "<<c1<<" c1\n";
        dp[i]= (ll)-9999999*(ll)9999999;
        loop(j,0,n)
        {
            ci=1<<j;
         //   cout<<ci<<" ci" <<"\n";
            if(i & ci)
            {
           //     cout<<dp[i-ci]<<" "<<n * l[j] + j*d[j]*(c1*( c1 - 1 )/ 2) - n * j * d[j] * (c1-1)<<"\n";
                hv1= n *1LL* l[j];
                hv1+= j*1LL*d[j]*1LL*(c1*1LL*( c1 - 1 )/ 2);
                hv1-= n * j *1LL* d[j] *1LL* (c1-1);
                dp[i]=maX(dp[i],dp[i-ci]+ hv1);
            }
        }
    }


    cout<<dp[tset]<<"\n";
    return 0;

}

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int n;
	scanf("%d", &n);
	vector<int> L(n), D(n);
	rep(i, n) scanf("%d", &L[i]);
	rep(i, n) scanf("%d", &D[i]);
	long long base = 0;
	rep(i, n)
		base += L[i] * n;
	//j???kiss?????d * ((j * (j-1) / 2) + (n - j) * j) ??
	vector<long long> d(n), a(n);
	rep(i, n)
		d[i] = D[i] * i;
	rep(j, n)//calculating number of tmes one has to contribute(subtract d[i]) if it has occur in j position
		a[j] = (ll)j * (j-1) / 2 + (ll)(n-j) * j;
//	cerr << "base: "<< base << endl;
//	cerr <<"d: "; rep(i, n) cerr << d[i] << ", "; cerr << endl;
//	cerr <<"a: "; rep(i, n) cerr << a[i] << ", "; cerr << endl;
	sort(all(d));
	sort(all(a));
	long long ans = base;
	rep(i, n)
		ans -= d[i] * a[n-1-i];//greedy
	printf("%lld\n", ans);
	return 0;
}
