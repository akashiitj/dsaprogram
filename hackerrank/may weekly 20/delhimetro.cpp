#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)
#define ll long long

vector<vector<pair<int, ll> > > g;
ll dis[51];
int mark[51];
void dfs(int cv,ll d)
{
    dis[cv]=d;
    mark[cv]=1;
    loop(i,0,g[cv].size())
    {
        if(mark[g[cv][i].first]==0)
            dfs(g[cv][i].first,d+g[cv][i].second);
    }
}

int main()
{
    int t,n,k,v1,v2;
    ll w;
    cin>>t;
    while(t--)
    {   g.clear();
        cin>>n>>k;
        g.resize((n+1));
        loop(i,0,n-1)
        {   dis[i+1]=0;
            mark[i+1]=0;
            cin>>v1>>v2>>w;
            g[v1].push_back(make_pair(v2,w));
            g[v2].push_back(make_pair(v1,w));
        }
       // cout<<" c1 "<<endl;
        dis[n]=0;
        mark[n]=0;
        dfs(1,0LL);
       // cout<<"d"<<endl;
        double dp[51][51]={};

        dp[0][1]=1.0;

        loop(i,1,k+1)
        {
            loop(j,1,n+1)
            {
                loop(x,0,g[j].size())
                dp[i][g[j][x].first]+=(double)dp[i-1][j]/g[j].size();
            }
        }
       double ans=0.0;
       loop(j,1,n+1)
        ans=ans+(dp[k][j]*(double)dis[j]);

         cout.setf(ios::fixed);
        cout << setprecision(7);
        cout<<ans<<endl;


    }
    return 0;
}
