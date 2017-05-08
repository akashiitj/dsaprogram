#include"stdio.h"
#include"vector"
using namespace std;
#define N 100000
vector<int> GR[N];
int G[N];
int price[N];
bool vis[N];
int incomingedge[N];

int findCycle(int init)
{
    if (vis[init]) return init;
    vis[init] = true;
    return findCycle(G[init]);
}

int main()
{

        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++)GR[i].clear();
        for(int i=0; i<n; i++)
        {
            int next;
            scanf("%d", &next);
            next--;
            GR[next].push_back(i);
            G[i] = next;
            vis[i] = 0;
            incomingedge[next]++;
        }

        int max_inedge=0;
        for(int i=0; i<n; i++)
        {
            max_inedge=max(max_inedge,incomingedge[i]);
        }

        int ans = 0;

        for(int v=0; v<n; v++)
        {
            if(vis[v])continue;
            int f = findCycle(v);
            int pRoot=f, root=G[pRoot];
            int val=1;
            do
            {

                pRoot = root;
                root = G[pRoot];
                val++;
            }
            while(pRoot != f);
            ans=max(ans,val);

        }
        printf("%d\n", ans);
        printf("%d\n", max_inedge);
    }


