#include<bits/stdc++.h>
using namespace std;
struct node
{
    int fr,to,cost;
} p[400];
//int graph[400][400]={0};
int c = 0,temp1 = 0,temp = 0;
struct ver
{
    int x;
    int y;
};
void prims(int *a,int b[][400],int i,int j,int ml)
{
    c=0;
    temp1 = 0;
    temp = 0;
    a[i] = 1;
    while (c < ml-1)
    {
        int min = 10000000;
        for (int i = 0; i < ml; i++)
        {
            if (a[i] == 1)
            {
                for (int j = 0; j < ml; )
                {
                    if (b[i][j] >= min || b[i][j] == 0)
                    {
                        j++;
                    }
                    else if (b[i][j] < min)
                    {
                        min = b[i][j];
                        temp = i;
                        temp1 = j;
                    }
                }
            }
        }
        a[temp1] = 1;
        p[c].fr = temp;
        p[c].to = temp1;
        p[c].cost = min;
        c++;
        b[temp][temp1] = b[temp1][temp]=10000000;
    }
    for (int k = 0; k < ml-1; k++)
    {
        cout<<p[k].fr+1<<" "<<p[k].to+1<<endl;
    }
    // cout<<endl;
}
int dis(int x,int y,int x1,int y1)
{
    return sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
}
int main()
{

    int t,i,V;
    cin>>t;
    while(t--)
    {
        cin>>V;
        int a[V];
        for ( i = 0; i < V; i++)
        {
            a[i] = 0;
        }
        int graph[400][400];
        ver ve[V];
        for( i=0; i<V; i++)
            cin>>ve[i].x>>ve[i].y;
        for( i=0; i<V; i++)
        {
            for(int j=i+1; j<V; j++)
                graph[i][j]=dis(ve[i].x,ve[i].y,ve[j].x,ve[j].y);

        }




        prims(a,graph,0,0,V);
    }
    return 0;
}
