#include<bits/stdc++.h>
using namespace std;
#define N 100000
vector<int> GR[N],RGR[N];
int G[N];
int price[N];
bool vis[N],rvis[N];
int incomingedge[N];
int already[N];

int findCycle(int init)//return a node of cycle
{

    if (vis[init]) return init;
    vis[init] = true;
    rvis[init] =true;
    if(GR[init][0]==-1)return -1;
    return findCycle(GR[init][0]);
}

void dfs(int sv)//for marking its incoming edge
{
    rvis[sv]=1;
    for(int i=0;i<RGR[sv].size();i++)
    {   if(rvis[RGR[sv][i]]==0)
        dfs(RGR[sv][i]);
    }
}

int main()
{

    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)GR[i].clear();
    for(int i=0; i<n; i++)
    {
        int next;
        scanf("%d",&next);
        GR[i].push_back(next);
        if(next!=-1)   RGR[next].push_back(i);//pushing in reverse edge graph
        incomingedge[next]++;//for telling ans of second part
        vis[i] = 0;
    }
    int max_inedge=0;
    for(int i=0; i<n; i++)
    {
        max_inedge=max(max_inedge,incomingedge[i]);
    }
    int ans = 0;
    int cyclelength;
    int hv,f;

    for(int v=0; v<n; v++)
    {

        if(vis[v]||rvis[v])continue;//this is so important condition
        dfs(v);
        f = findCycle(v);
        if(f!=-1)
        {

            cyclelength=1;
            hv=f;
            while(GR[hv][0]!=f)
            {
                hv=GR[hv][0];

                cyclelength++;
            }
            ans=max(ans,cyclelength);
           }


    }
    printf("%d\n", ans);
    printf("%d\n", max_inedge);

}
