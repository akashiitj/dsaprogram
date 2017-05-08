#include <vector> 
#include <queue>
#include <map> 
#include <set>
#include <utility> //Pair
#include <algorithm>
#include <sstream> // istringstream>> ostring stream<<
#include <iostream> 
#include <iomanip> 
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <bitset>
#include <limits>


using namespace std;
#define REP(a, b, c) for(int a = b; a < c; a++)
#define asd(x)              cout<<__LINE__<<" :: "<<#x<< ": "<<x<<endl;
#define asdf(x, y)          cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<endl;
typedef pair<int,int> ii;
typedef long long LL;

map<LL, int> dp;

int P[35] = {2,3,5,7,11,13,17,19,23,29,
31,37,41,43,47,53,59,61,67,71,
73,79,83,89,97,101,103,107,109,113,
127,131,137,139,149};


bool isPrime(int sum){
	if(sum == 1) return true;
	REP(i, 0, 35){
		if(P[i] == sum) return true;
	}
	return false;
}

vector<LL> primes(LL x){
	vector<LL> ret;

	for(LL i = 2; i*i <= x; i++){

		int cnt = 0;
		while(x % i == 0){
			x = x / i;
			cnt++;
		}
		if(cnt) ret.push_back(i);
	}
	if(x > 2) ret.push_back(x);
	return ret;
}

int rec(LL x){

	if(dp.count(x)){
		return dp[x];
	}

	LL y = x, sum = 0;
	while(y) sum += y % 10, y = y / 10;

	
	if(isPrime(sum)){
		return dp[x] = false;
	}

	vector<LL> Primes = primes(x);

	for(int i = 0; i < Primes.size(); i++){
		LL y = x;
		while(y % Primes[i] == 0){
			y /= Primes[i];
		}
		if(rec(y) == false){
			return dp[x] = true;
		}
	}

	return dp[x] = false;

}

int main(){

	int test;
	scanf("%d", &test);
	REP(i, 0, test){
		string ans = "Seymour";
		LL val;
		scanf(	"%lld", &val);
		if(rec(val)){;
			ans = "Laurence";
		}
		printf("Case #%d: ", i+1);
		cout << ans << "\n";
	}
	
	return 0;
}
