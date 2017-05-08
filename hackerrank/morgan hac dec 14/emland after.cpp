#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;

#define inp_s     ios_base::sync_with_stdio(false)
#define DRT()     int test_case;cin>>test_case;while(test_case--)

#define VI        vector<int>
#define VS        vector<string>
#define VLL       vector<LL>
#define PII       pair<int,int>
#define all(c)    c.begin(),c.end()
#define sz(c)     c.size()
#define clr(c)    c.clear()
#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair

#define GI(x)     scanf("%d",&x)

#define FOR(i,a,b)      for(int i=a;i<b;i++)
#define RFOR(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define MOD       1000000007
#define EPS       1e-7

#define case(x)   cout<<"Case "<<x<<": ";

vector<VI> edges;//shows which intersection are connected to which intersection
VI counter; // count no. of nodes below it.
VI visited;//used in dfs

int dfs(int source)
{
      if(visited[source]) return 0;
      visited[source] = 1;
      FOR(i,0,sz(edges[source]))
      {
            int x = edges[source][i];
            counter[source] += dfs(x);
      }
      return counter[source]+1;
}

int main()
{
      inp_s;
      DRT()
      {
            int n,k;
            cin>>n>>k;
            clr(edges);
            clr(visited);
            clr(counter);

            edges.resize(n);
            VLL init_cost(n-1), new_cost(n-1);
            visited.resize(n);
            vector<PII> real_edges;
            FOR(i,0,n-1)
            {
                  int a,b;
                  LL c,d;
                  cin>>a>>b>>c>>d;
                  a--;
                  b--;
                  real_edges.pb(mp(a,b));
                  edges[a].pb(b);
                  edges[b].pb(a);
                  init_cost[i] = c;
                  new_cost[i] = d;
            }
            counter.resize(n);
            dfs(0);
            FOR(i,0,n) assert(counter[i]<n);
            VLL set_weight(n-1);
            LL sum = 0;
            FOR(i,0,n-1)
            {
                  LL childs = min(counter[real_edges[i].first],counter[real_edges[i].second]) + 1LL;
                  childs *= (n-childs);
                  sum += childs*init_cost[i];
                  set_weight[i] = childs*(new_cost[i] - init_cost[i]);
            }
            sort(all(set_weight));

            FOR(i,0,k)
            {
                  if(set_weight[i]>=0)
                        break;
                  else
                        sum += set_weight[i];
            }

            cout<<sum<<endl;

      }
      return 0;
}
