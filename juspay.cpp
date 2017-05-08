#include<bits/stdc++.h>
using namespace std;
#define N 100000
vector<int> GR[N],RGR[N];//graph and graph formed by reversing edge
bool vis[N],rvis[N];
int incomingedge[N];

int findCycle(int init)//return a node of cycle
{

    if (vis[init]) return init;
    vis[init] = true;
    rvis[init] =true;
    if(GR[init][0]==-1)return -1;
    return findCycle(GR[init][0]);
}

void dfs(int sv)//for marking its incoming edge becoz their is no need to visit them
{
    rvis[sv]=1;
    for(int i=0; i<RGR[sv].size(); i++)
    {
        if(rvis[RGR[sv][i]]==0)
            dfs(RGR[sv][i]);
    }
}

int minsteps(int i,int j)//anser is either of two given vertex becoz their is only one incoming edge on each vertex
{
    int ans=0;
    int sv;

    int step1=0,ans1=INT_MAX;
    sv=i;
    memset(vis,0,sizeof vis);
    while(vis[sv]!=1)
    {
        vis[sv]=1;
        sv=GR[sv][0];
        step1++;
        if(sv==-1)break;
        if(sv==j)
        {
            ans1=j;
            break;
        }
    }

    int step2=0,ans2=INT_MAX;
    sv=j;
    memset(vis,0,sizeof vis);
    while(vis[sv]!=1)
    {
        vis[sv]=1;
        sv=GR[sv][0];
        step2++;
        if(sv==-1)break;
        if(sv==i)
        {
            ans2=i;
            break;
        }
    }

    if(ans2==ans1&&ans2==INT_MAX)  return -1;
    if(ans1!=INT_MAX&&ans2!=INT_MAX)return step1<step2 ? j : i;
    if(ans1==INT_MAX)return i;
    else  return j;
}

int main()
{

    int n,sv,dv;
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
    scanf("%d%d",&sv,&dv);
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

    int ans1=minsteps(sv,dv);

    if(ans==1) printf("-1\n");
    else printf("%d\n", ans);

    printf("%d\n", max_inedge);

    if(ans1==-1) printf("not possible to reach\n");
    printf("%d\n", ans1);


}
