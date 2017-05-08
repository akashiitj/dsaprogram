/*
Author: aseemraj
Problem: A
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;
int cost[505][505][25];
int ans[25][505];
int t, n, m, k, u, v;
vector<int> adj[505];


struct compare
{
    bool operator()(const pair<int, pair<int, int> > &p,const pair<int, pair<int, int> > &q)
    {
        return p.second.first > q.second.first;
    }
};

void solve(int src, int instant)
{
    vector<int> dist(505, INF);
    int visited[110000]={0};
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, compare> q;
    q.push(make_pair(src,make_pair(0, instant)));
    dist[src]=0;
    while(!q.empty())
    {
        int vtx1 = q.top().first;
        int tim = q.top().second.second;
        q.pop();
        if(!visited[vtx1])
        {
            for(int i = 0; i < adj[vtx1].size(); i++)
            {
                int vtx2 = adj[vtx1][i], dis = cost[vtx1][vtx2][tim];
                if((dist[vtx2] > dist[vtx1] + dis) && (!visited[vtx2]))
                {
                    dist[vtx2] = dist[vtx1] + dis;
                    q.push(make_pair(vtx2,make_pair(dist[vtx2], (tim + dis) % 24)));
                }
            }
            visited[vtx1] = 1;
        }
    }

    for(int i = 2; i <= n; i++)
    {
        if(dist[i] == INF)
            ans[instant][i] = -1;
        else
            ans[instant][i] = dist[i];
    }
}


int main()
{
    freopen("1.in","r",stdin);
    freopen("1o.out","w",stdout);
    int test;
    cin>>test;
    for(int t = 1; t <= test; t++)
    {
        memset(ans, 0, sizeof(ans));
        memset(cost, 0, sizeof(cost));

        cin>>n>>m>>k;
        for(int i = 0;i <= n ;i++)
            adj[i].clear();
        for(int i = 0;i < m; i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            for(int j = 0;j < 24; j++)
            {
                cin>>cost[u][v][j];
                cost[v][u][j] = cost[u][v][j];
            }
        }

        for(int i = 0;i < 24; i++)
            solve(1, i);

        cout<<"Case #"<<t<<": ";
        for(int i = 0; i < k; i++)
        {
            cin>>u>>v;
            cout<<ans[v][u]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
