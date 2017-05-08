#include<iostream>
using namespace std;
main()
{
    int n;
    cin>>n;
    int a[n],a1[n][2];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {  a1[i][0]=0;
        for(int j=0;j<=i;j++)
        {
            if(a[j]==a[i])
                a1[i][0]++;
        }
    }
     for(int i=0;i<=n-1;i++)
    {  a1[i][1]=0;
        for(int j=i;j<n;j++)
        {
            if(a[j]==a[i])
                a1[i][1]++;
        }
    }
    int c=0;
     for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a1[i][0]>a1[j][1])c++;
        }
    }
    cout<<c<<endl;

}
