#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define all(c) c.begin(), c.end()
#define pi pair<int,int>
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, k, x, y, cnt=0;
    cin>>n>>m>>k;
    int cell[101][101]={{0}};
    int tcell[101][101]={{0}};
    int row[101] = {0};
    int col[101] = {0};
    int trow[101] = {0};
    int tcol[101] = {0};
    loop(i, 0, k)
    {
        cin>>x>>y;
        cell[x][y]=1;
        tcell[x][y]=1;
    }

    loop(i, 1, n+1)
    {
        loop(j, 1, m+1)
        {
            if(cell[i][j]==1)
            {
                row[i]++;
                col[j]++;
                trow[i]++;
                tcol[j]++;
            }
        }
    }
    x = y = 1;
    while(x<n+1&&y<m+1)
    {
        if(row[x]<=col[y])
        {
            loop(j, y, m+1)
            {
                if(cell[x][j]==0)
                {
                    cnt++;
                    for(int p=j;p<m+1&&cell[x][p]!=1;p++)cell[x][p]=2;
                    for(int p=j;p>0&&cell[x][p]!=1;p--)cell[x][p]=2;
                }
            }
            loop(j, y, m+1)if(cell[x][j]==1)col[j]--;
            x++;
        }
        else if(row[x]>col[y])
        {
            loop(j, x, n+1)
            {
                if(cell[j][y]==0)
                {
                    cnt++;
                    for(int p=j;p<n+1&&cell[p][y]!=1;p++)cell[p][y]=2;
                    for(int p=j;p>0&&cell[p][y]!=1;p--)cell[p][y]=2;
                }
            }
            loop(j, x, n+1)if(cell[j][y]==1)row[j]--;
            y++;
        }
    }
    cout<<cnt<<endl;
    x = y = 1;
    while(x<n+1&&y<m+1)
    {
        if(trow[x]<=tcol[y])
        {
            loop(j, y, m+1)
            {
                if(tcell[x][j]==0)
                {
                    cout<<x<<' '<<j<<' '<<0<<endl;
                    for(int p=j;p<m+1&&tcell[x][p]!=1;p++)tcell[x][p]=2;
                    for(int p=j;p>0&&tcell[x][p]!=1;p--)tcell[x][p]=2;
                }
            }
            loop(j, y, m+1)if(tcell[x][j]==1)tcol[j]--;
            x++;
        }
        else if(trow[x]>tcol[y])
        {
            loop(j, x, n+1)
            {
                if(tcell[j][y]==0)
                {
                    cout<<j<<' '<<y<<' '<<1<<endl;
                    for(int p=j;p<n+1&&tcell[p][y]!=1;p++)tcell[p][y]=2;
                    for(int p=j;p>0&&tcell[p][y]!=1;p--)tcell[p][y]=2;
                }
            }
            loop(j, x, n+1)if(tcell[j][y]==1)trow[j]--;
            y++;
        }
    }
    return 0;
}
