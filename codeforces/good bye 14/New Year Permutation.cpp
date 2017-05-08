#include<bits/stdc++.h>
#define loop(i, a, b)  for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
bool visited[500];
vector<int> comp1[500];//keep track of differnt dfs according to no.
vector<int> comp2[500];//keep track of differnt dfs according to value
int n;
bool a[500][500], ta[500][500];
int p[500], ans[500];
void dfs(int v, int component)
{
    visited[v] = 1;
    comp1[component].push_back(v);
    comp2[component].push_back(p[v]);
    loop(i, 1, n+1)
        if(a[v][i] && !visited[i])
            dfs(i, component);
}
int main()
{
    ios_base::sync_with_stdio(0);
    int component, x;
    string st;
    cin>>n;
    loop(i, 1, n+1)cin>>p[i];
    loop(i, 1, n+1)
    {
        cin>>st;
        loop(j, 1, n+1)
            a[i][j] = (st[j-1]=='1'?1:0);
    }
    component = 0;//counts number of different dfs means different maximal connected component
    loop(i, 1, n+1)
        if(!visited[i])
            dfs(i, component++);
    loop(i, 0, n)
    {
        cout<<"i "<<i<<endl;
         if(comp1[i].size()==0)break;
        loop(q,0,comp1[i].size())
        {
            cout<<comp1[i][q]<<" ";
        }
        cout<<endl;
         loop(q,0,comp2[i].size())
        {
            cout<<comp2[i][q]<<" ";
        }
       cout<<"after"<<endl;
        sort(comp1[i].begin(), comp1[i].end());//do sorting of no that are connected
        sort(comp2[i].begin(), comp2[i].end());//do sorting of value
         loop(q,0,comp1[i].size())
        {
            cout<<comp1[i][q]<<" ";
        }cout<<endl;
         loop(q,0,comp2[i].size())
        {
            cout<<comp2[i][q]<<" ";
        }
        loop(j, 0, comp1[i].size())//place sorted value in sorted number
            ans[comp1[i][j]] = comp2[i][j];
    }
    loop(i, 1, n+1)cout<<ans[i]<<' ';
    return 0;
}
