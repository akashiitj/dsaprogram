#include<iostream>
using namespace std;
int f(int **a,int m,int n)
{
    int ha[m][n],max1=0;
    for(int i=0;i<m;i++)
    {   cout<<"m"<<endl;
        ha[i][0]=a[i][0];
    }
     for(int i=0;i<n;i++)
    {   cout<<"n"<<endl;
        ha[0][i]=a[0][i];
    }
     for(int i=1;i<m;i++)
    {   cout<<"m"<<endl;
        for(int j=1;j<n;j++)
        {   cout<<"n"<<endl;
            if(a[i][j]==1){
            ha[i][j]=min(min(ha[i-1][j],ha[i-1][j-1]),ha[i][j-1])+1;
            max1=max(max1,ha[i][j]);
        }
        }


    return max1;

}
main()
{
    int **a;
    int m,n;
    cin>>m;
    cin>>n;
    a=new int*[m];
    for(int i=0;i<m;i++)
    {   a[i]=new int[n];
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    cout<<f(a,m,n);
}
