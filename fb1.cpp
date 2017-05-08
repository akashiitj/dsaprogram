
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


typedef long long ll;
typedef double float64;

//START

ll prime(ll n)
{

    ll c = 0;
    ll rc=0;
    while(n%2==0)
    {
        c++;
        n = n>>1;
    }
    if(c!=0)rc++;

    for(ll i=3; i<=sqrt((float)n); i=i+2)
    {
        c = 0;
        while(n%i==0)
        {
            c++;
            n = n/i;
        }
        if(c!=0)rc++;
    }
    if (n > 2 )
        rc++;
        return rc;

}

int main() {
    std::ios_base::sync_with_stdio(false);
    int TC;
    cin>>TC;
    //TC=1;

    while(TC--) {
        int a,b,k;
        int ans=0;
        cin>>a>>b>>k;
        for(int x=a;x<=b;x++)
      {

        if(prime(x)==k)
        ans++;
      }
      cout<<ans<<endl;
    }
    return 0;
}

