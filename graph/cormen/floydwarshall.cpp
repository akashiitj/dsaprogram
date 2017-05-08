#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)

int g[100][100];

main()
{  int n;
    cin>>n;
    loop(i,0,n)
    loop(j,0,n)
    if(i!=j)g[i][j]=10000;

    int v1,v2,w;
    while(true)
    {
        cin>>v1;
        if(v1==-1)break;
        cin>>v2>>w;
        g[--v1][--v2]=w;
        g[v2][v1]=w;
    }

    loop(k,0,n)
    loop(i,0,n)
    loop(j,0,n)
    if((g[i][k]+g[k][j])<g[i][j])g[i][j]=g[i][k]+g[k][j];

     loop(i,0,n){
    loop(j,0,n)
    cout<<g[i][j]<<" ";

    cout<<endl;
}
}
