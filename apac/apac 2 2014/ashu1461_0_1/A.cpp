// asdasdasda as dasd 
#include <bits/stdc++.h>
using namespace std;
#define REP(a,b,c) for(int a=b;a<c;a++)
#define asd(x)              cout<<__LINE__<<" :: "<<#x<< ": "<<x<<endl;
#define asdf(x, y)          cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<endl;
typedef pair<int,int> ii;
typedef long long LL;

int N,M;
const int max1 = 102;
const int MOD = 1e9 + 7;
int dp[max1][max1];
LL mod(LL a){
    return a%MOD;
}
int rec(int n, int left){
    int prev = M-left;
    int &ret = dp[n][left];

    if(n == 0){
        return ret = (left == 0);
    }
    if(ret != -1) return ret;

    // take a prev here
    ret = 0;
    if(prev){
        ret = mod((LL)prev*rec(n-1, left));
    }

    if(left){
        LL here = mod((LL)left*rec(n-1, left-1));
        ret = mod(ret + here);
    }
    return ret;
}

int main(){
    int test;
    cin >> test;
    REP(t, 0 ,test){
        cin >> M >> N;
        memset(dp, -1, sizeof dp);
        printf("Case #%d: %d\n", t+1, rec(N,M));
    }
    return 0;
}
