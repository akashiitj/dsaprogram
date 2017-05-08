
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <string.h>
#include <cassert>
#include <climits>

using namespace std;

const int oo = int(2e9) + 9;
const double eps = 1e-9;
const double pi = 3.14159265358979323846264338327950;

#define debug printf("ERROR DETECTED...!!\n");
#define debug1(p)        cerr << #p << ": " << p << endl;
#define debug2(p, q)     cerr << #p << ": " << p << " | " << #q << ": " << q << endl;
#define debug3(p, q, r)  cerr << #p << ": " << p << " | " << #q << ": " << q << " | " << #r << ": " << r << endl;

#define  takeinput() freopen("ip.txt","r",stdin);
#define  takeoutput() freopen("op.txt","w",stdout);

typedef vector < int > vi;
typedef pair < int, int> ii;
typedef vector < ii > vii;

#define trvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define trvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define pb push_back
#define mp make_pair


typedef long long int64;
typedef double float64;

//START

bitset<10000005> bs;
vi primes;
int cnt[10000005];
int sum[10][10000005];

void sieve(int n) {
    bs.set();
    bs.set(0,false);
    bs.set(1,false);
    for(int i=2;i*i<=n;i++)
        if(bs.test(i))
            for(int j=i*i;j<=n;j+=i)
                bs.set(j,false);

    for(int i=0;i<=n;i++)
        if(bs.test(i))
            primes.pb(i);

    for(int i=0;i<primes.size();i++)
        for(int j=primes[i];j<=n;j+=primes[i])
            cnt[j]++;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int TC;
    cin>>TC;
    //TC=1;

    sieve(10000002);
    for(int i=1;i<=10000000;i++)
        for(int j=1;j<=8;j++)
            sum[j][i] = sum[j][i-1] + (cnt[i]==j);

   for(int i=1;i<=TC;i++) {
        int a,b,k;
        cin>>a>>b>>k;

        if(k>8) cout<<"Case #"<<i<<": 0"<<endl;
        else
            cout<<"Case #"<<i<<": "<<sum[k][b]-sum[k][a-1]<<endl;
        //cout<<sum[k][b]-sum[k][a-1]<<endl;
    }
    return 0;
}
