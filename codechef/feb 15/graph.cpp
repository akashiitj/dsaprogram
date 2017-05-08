#include <bits/stdc++.h>

using namespace std;
#define loop(i,a,b) for(ull i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;

ll mod(ll no)
{
    return (no%1000000007);
}

struct node1
{
    ll val;
    ll px;
    ll py;
};

node1 node[111][113];

int main()
{
    std::ios_base::sync_with_stdio(false);
    ll n,m,k;
    cin>>n>>m>>k;
    node[0][0].val=1;

    ll x,y,a,b;

    loop(i,1,n+2)
    {
        loop(j,1,m+1)
        {
            node[j][i].val=0;
            node[j][i].px=-1;
            node[j][i].py=-1;
        }
    }

    while(k--)
    {
        cin>>x>>y>>a>>b;
        node[b][a].px=x;
        node[b][a].py=y;
    }
    ll ps=1,cs;
    loop(i,1,n+1)
    {
        cs=0;
        loop(j,1,m+1)
        {
            if(node[j][i].px!=-1)
            {
                node[j][i].val=node[j][i].val+node[node[j][i].py][node[j][i].px].val;
                cout<<node[j][i].px<<" "<<node[j][i].py<<" ";
            }
            node[j][i].val=node[j][i].val+ps;
            node[j][i].val=mod(node[j][i].val);
            cs=cs+node[j][i].val;
            cs=mod(cs);
            cout<<node[j][i].val<<"     ";
        }
        ps=cs;
        cout<<endl;
    }

    if(node[0][n+1].px!=-1)
    {
        node[0][n+1].val=node[0][n+1].val+node[node[0][n+1].py][node[0][n+1].px].val;
    }
    node[0][n+1].val=node[0][n+1].val+ps;
   // node[0][n+1].val=mod(node[0][n+1].val)+ps;
    node[0][n+1].val=mod(node[0][n+1].val);
    cout<<node[0][n+1].val<<endl;
    return 0;
}
