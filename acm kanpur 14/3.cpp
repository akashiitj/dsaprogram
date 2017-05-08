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
typedef pair<int, ii> iii;
typedef long long LL;

const int MAX = 501;
vector<ii> G[MAX];

int ans[MAX][24][24];
int N, M, K;
int EDGE[2002][24];


void DIJ(int T){

	REP(i, 2, N+1){
		REP(j, 0, 24){
			ans[i][j][T] = INT_MAX;
		}
	}

	set< iii > S; // ans -> (idx, T);

	S.insert(iii(0, ii(1, T))); // if I start at 1 on time T
	ans[1][0][T] = 0;


	while(S.size()){
		iii t = *S.begin();
		S.erase(S.begin());
		int idx = t.second.first, time = t.second.second, wt = t.first;

		if(wt > ans[idx][time][T]) continue;

		REP(i, 0, G[idx].size()){
			int u = G[idx][i].first, v = G[idx][i].second; // v == eno

			REP(t, 0, 24){
				int w_extra = wt + t + EDGE[v][(time + t) % 24];
				int rt = (time + t + EDGE[v][(time + t) % 24]) % 24;
				if(ans[u][rt][T] > w_extra){
					S.erase(iii(ans[u][rt][T], ii(u, rt)));
					ans[u][rt][T] = w_extra;
					S.insert(iii(ans[u][rt][T], ii(u, rt)));
				}
			}
		}

	}



}


int main(){
	int test;
	scanf("%d", &test);
	REP(i, 0, test){
		scanf("%d %d %d", &N, &M, &K);
		REP(i, 1, N+1) G[i].clear();
		REP(j, 0, M){
			int x, y;
			scanf("%d %d", &x, &y);
			G[x].push_back(ii(y, j));
			G[y].push_back(ii(x, j));
			REP(k, 0, 24) scanf("%d", &EDGE[j][k]);
		}
		REP(i, 0, 24) DIJ(i);
		printf("Case #%d:", i+1);

		while(K--){
			int D, S;
			scanf("%d %d", &D, &S);
			int ANS = INT_MAX;
			REP(i, 0, 24){
				ANS = min(ANS, ans[D][i][S]);
			}
			if(ANS == INT_MAX) ANS = -1;
			printf(" %d", ANS);
		}
		cout << endl;
	}
	return 0;
}
