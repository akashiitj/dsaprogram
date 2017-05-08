#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn = 1e2+ 10;
#define rep(i,a,b) for(LL i=(a);i<=(b);i++)
#define pb push_back
std::vector<LL>path;
const LL INF=1<<20;
struct PoLL
{
    LL x,y;
    bool operator < (const PoLL &a)const
    {
        return x<a.x||(x==a.x)&&y<a.y;
    }
};
std::vector<PoLL>P;
char mat[maxn][maxn];
LL vis[maxn][maxn];
LL w,h,s,e;
LL d[1<<20][20]= {-1};
LL dx[]= {-1,0,0,1};
LL dy[]= {0,-1,1,0};
LL dist[25][25];
LL visited[101][101]= {-1};
class Orienteering
{

public:

    LL main();
    LL init();

    void visi(int x1,int y1)
    {
        visited[x1][y1]=1;
        int x=x1-1;
        int u=x1+1;
        int y=y1-1;
        int v=y1+1;
        if(x>=0&&visited[x][y1]!=1)
        {
            if(mat[x][y1]!='#')
                visi(x,y1);
        }
        if(u<h&&visited[u][y1]!=1)
        {
            if( mat[u][y1]!='#')
                visi(u,y1);
        }
        if(y>=0&&visited[x1][y]!=1&&mat[x1][y]!='#')
            visi(x1,y);
        if(v<w&&visited[x1][v]!=1&&mat[x1][v]!='#')
            visi(x1,v);

        return;

    }
};
LL Orienteering::init()
{
    LL flag=0;
    cin>>w>>h;
    for(int it1=0; it1<h; it1++)
    {
        for(int jt1=0; jt1<w; jt1++)
        {
            visited[it1][jt1]=-1;
        }
    }
    if (w > 100 || h > 100)
    {
        flag=1;
    }
    map<PoLL,LL>id;
    P.clear();
    path.clear();
    memset(d,100,sizeof d);
    memset(dist,100,sizeof dist);
    LL calpha=0,cG=0,cS=0;
    for(LL i=0; i<h; i++)
    {

        cin>>mat[i];
        for(LL j=0; mat[i][j]; ++j)
        {
            char &c=mat[i][j];
            if(c=='S'||c=='G'||c=='@')
            {
                if(c=='@')calpha++;
                if(c=='G')cG++;
                if(c=='S')cS++;
                P.pb((PoLL)
                {
                    i,j
                });
                LL sz=P.size();
                id[P[sz-1]]=sz;
                if(c=='S')s=sz-1;
                else if(c=='G')e=sz-1;
                path.pb(sz-1);
            }
        }
    }
    if(calpha>18||flag==1||cS>1||cG>1)return -1;
    int hv1=1;
    int x1,y1;

    flag=0;
    for(int it1=0; it1<h; it1++)
    {
        for(int jt1=0; jt1<w; jt1++)
        {
            if(mat[it1][jt1]!='#')
            {
                x1=it1;
                y1=jt1;
                flag=1;
                break;
            }
        }
        if(flag==1)break;
    }
    //  cout<<x1<<" "<<y1<<endl;
    visi(x1,y1);
    flag=0;

    for(int it1=0; it1<h; it1++)
    {
        for(int jt1=0; jt1<w; jt1++)
        {
            int fd=0;
            if(mat[it1][jt1]=='S'||mat[it1][jt1]=='G'||mat[it1][jt1]=='@')
                fd=1;
            if(fd==1&&visited[it1][jt1]==-1)
            {
                x1=it1;
                y1=jt1;
                flag=1;
                break;
            }
        }
        if(flag==1)break;
    }
    if(flag==1)return -1;
    for(LL i=0; i<path.size(); i++)
    {
        PoLL now=P[path[i]];
        LL x=path[i];

        dist[x][x]=0;
        memset(vis,0,sizeof vis);
        vis[now.x][now.y]=1;
        queue<PoLL>q;
        q.push(now);

        while(!q.empty())
        {
            now=q.front();
            q.pop();
            for(LL i=0; i<4; i++)
            {
                LL nx=now.x+dx[i],ny=now.y+dy[i];
                if(nx>=0&&nx<h&&ny>=0&&ny<w&&mat[nx][ny]!='#'&&!vis[nx][ny])
                {
                    PoLL tp=(PoLL)
                    {
                        nx,ny
                    };
                    q.push(tp);
                    vis[nx][ny]=vis[now.x][now.y]+1;
                    if(id[tp])
                    {
                        dist[x][id[tp]-1]=vis[now.x][now.y];

                    }
                }

            }

        }

    }

    d[1<<s][s]=0;
    LL M=path.size();
    for(LL i=0; i<(1<<M); ++i)
    {
        for(LL j=0; j<M; j++)
        {
            LL p=path[j];
            for(LL k=0; 1<<k<=i; k++)
            {
                if(i&(1<<k))
                {
                    d[i|(1<<p)][p]=min(d[i|(1<<p)][p],d[i][k]+dist[k][p]);
                }
            }
        }
    }
    return d[(1<<M)-1][e];

}

LL Orienteering::main()
{
    return init();
}
int main(LL argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    Orienteering o;
    cout<<o.main()<<endl;


    return 0;
}
