#include<iostream>
using namespace std;
int cluster(int **p,int **ha,int m,int n,int i,int j,int c)
{  ha[i][j]=c;
    if((i+1)>=0 && i+1<m &&j>=0 &&j<n)
    {
        if(p[i+1][j]!=0)
        {  // p[i+1][y]=c;
            if(ha[i][j]>ha[i+1][j]&&ha[i+1][j]!=0)
                ha[i][j]=ha[i+1][j];
            else
                ha[i+1][j]=ha[i][j];
        }

    }


    if((i+1)>=0 && i+1<m &&j+1>=0 &&j+1<n)
    {
        if(p[i+1][j+1]!=0)
        {  // p[i+1][y]=c;
            if(ha[i][j]>ha[i+1][j+1]&&ha[i+1][j+1]!=0)
                ha[i][j]=ha[i+1][j+1];
            else
                ha[i+1][j+1]=ha[i][j];
        }

    }
    if((i)>=0 && i<m &&j+1>=0 &&j+1<n)
    {
        if(p[i][j+1]!=0)
        {  // p[i+1][y]=c;
            if(ha[i][j]>ha[i][j+1]&&ha[i][j+1]!=0)
                ha[i][j]=ha[i][j+1];
            else
                ha[i][j+1]=ha[i][j];
        }

    }
    if((i-1)>=0 && i-1<m &&j+1>=0 &&j+1<n)
    {
        if(p[i-1][j+1]!=0)
        {  // p[i+1][y]=c;
            if(ha[i][j]>ha[i-1][j+1]&&ha[i-1][j+1]!=0)
                ha[i][j]=ha[i-1][j+1];
            else
                ha[i-1][j+1]=ha[i][j];
        }

    }
     if((i-1)>=0 && i-1<m &&j>=0 &&j<n)
    {
        if(p[i-1][j]!=0)
        {  // p[i+1][y]=c;
            if(ha[i][j]>ha[i-1][j]&&ha[i-1][j]!=0)
                ha[i][j]=ha[i-1][j];
            else
                ha[i-1][j]=ha[i][j];
        }

    }
     if((i-1)>=0 && i-1<m &&j-1>=0 &&j-1<n)
    {
        if(p[i-1][j-1]!=0)
        {  // p[i+1][y]=c;
            if(ha[i][j]>ha[i-1][j-1]&&ha[i-1][j-1]!=0)
                ha[i][j]=ha[i-1][j-1];
            else
                ha[i-1][j-1]=ha[i][j];
        }

    }
    if((i)>=0 && i<m &&j-1>=0 &&j-1<n)
    {
        if(p[i][j-1]!=0)
        {  // p[i+1][y]=c;
            if(ha[i][j]>ha[i][j-1]&&ha[i][j-1]!=0)
                ha[i][j]=ha[i][j-1];
            else
                ha[i][j-1]=ha[i][j];
        }

    }
    if((i+1)>=0 && i+1<m &&j-1>=0 &&j-1<n)
    {
        if(p[i+1][j-1]!=0)
        {  // p[i+1][y]=c;
            if(ha[i][j]>ha[i+1][j-1]&&ha[i+1][j-1]!=0)
                ha[i][j]=ha[i+1][j-1];
            else
                ha[i+1][j-1]=ha[i][j];
        }

    }

}
main()
{
    int m,n,i,j;
    cin>>m>>n;
//    int a[m][n],haa[m][n];
  int **a,**ha;
a = new int *[m];
for(int i = 0; i <m; i++)
    a[i] = new int[n];
ha = new int *[m];
for(int i = 0; i <m; i++)
    ha[i] = new int[n];

    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
          {
              cin>>a[i][j];
              ha[i][j]=0;

          }

          int c=1;

    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {   if(a[i][j]==1){
            cluster(a,ha,m,n,i,j,c);
            c++;
        }
        }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
          {
              cout<<ha[i][j]<<"  ";
        }
cout<<endl;
}
}
