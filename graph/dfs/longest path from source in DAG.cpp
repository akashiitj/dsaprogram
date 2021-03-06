#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

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

vi g[100];
vi dis[100];
int vis[100]= {};
int ht[100]= {};

vi ts;

int maxdis[100];

int dfsts(int sv)
{
    vis[sv]=1;
    ht[sv]=1;
    loop(i,0,g[sv].size())
    {
        if(vis[g[sv][i]]==0)
        {

            if(dfsts(g[sv][i]))
            {
                return 1;
            }
        }
        else if(ht[g[sv][i]])//you are making mistake here,you are at a vertex(sv) and you are going to visit its child and it is not its parent
        {
            return 1;
        }
    }
    ts.pb(sv);
    ht[sv]=0;
    return 0;
}


int main()
{
    int n,m;
    int v1,v2,w;
    le2(n,m);
    loop(i,0,m)
    {
        le2(v1,v2);
        le(w);
        g[v1].pb(v2);
        dis[v1].pb(w);
    }
    cout<<"enter source\n";
    int sv;
    le(sv);
    int flag=0;
    loop(i,0,n)
    {
        maxdis[i]=-100000;
        if(vis[i]==0&&dfsts(i)==1)
        {
            flag=1;
            cout<<"finding longest path is not possible\n";
            return 0;
        }

    }
    if(flag==0)
    {
        cout<<"finding longest path possible\n";
        reverse(ts.begin(),ts.end());
        int i1;

        loop(i,0,ts.size())
        cout<<ts[i]<<" ";
        cout<<"\n";

        loop(i,0,ts.size())
        {
            if(ts[i]==sv)
                i1=i;
        }
        maxdis[sv]=0;

        loop(i,i1,ts.size())
        {
            int v=ts[i];
            loop(j,0,g[v].size())
            {
                maxdis[g[v][j]]=maX( maxdis[g[v][j]],maxdis[v]+dis[v][j]);
            }
        }
        loop(i,0,n)
        cout<<maxdis[i]<<" ";
        cout<<"\n";

    }
    return 0;
}









#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g,wgt;
vector<int> topo,d;
vector<bool> vis,tempVis;

void addEdge(int u, int v, int weight) {
  g[u].push_back(v);
  wgt[u].push_back(weight);
}

bool ts(int node){
  vis[node] = true;
  tempVis[node] = true;
  for(int i=0;i<g[node].size();i++){
  	int adjNode = g[node][i];
    if(!vis[adjNode]){
    	if(!ts(adjNode))
          return false;
    }else if(tempVis[adjNode]){
    	return false;
    }
  }
  topo.push_back(node);
  tempVis[node] = false;
  return true;

}

 
int main() 
{ 
	// Create a graph given in the above diagram. 
	// Here vertex numbers are 0, 1, 2, 3, 4, 5 with 
	// following mappings: 
	// 0=r, 1=s, 2=t, 3=x, 4=y, 5=z 
	g.resize(6);
    wgt.resize(6);
    d.resize(6,0);
    vis.resize(6,false);
    tempVis.resize(6,false);
   
    addEdge(0, 1, 5); 
    addEdge(0, 2, 3); 
    addEdge(1, 3, 6); 
    addEdge(1, 2, 2); 
    addEdge(2, 4, 4); 
    addEdge(2, 5, 2); 
    addEdge(2, 3, 7); 
    addEdge(3, 5, 1); 
    addEdge(3, 4, -1); 
    addEdge(4, 5, -2); 
  
    if(ts(1)){
      cout<<"Possible\n";
      
      reverse(topo.begin(),topo.end());
      
      for(int i=0;i<topo.size();i++){
      	int cur = topo[i];
      	for(int j=0;j<g[cur].size();j++){
      		int adj = g[cur][j];
      		d[adj]=max(d[adj],d[cur]+wgt[cur][j]);
      	}
      }
      for(int i=0;i<d.size();i++){
      	cout<<d[i]<<" ";
      }
    }else {
      cout<<"notPossible";
    } 

	return 0; 
} 

