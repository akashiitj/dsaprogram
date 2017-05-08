#include<iostream>
using namespace std;
void shift(int a[],int i,int n)
{
    while(i<n&&a[i]!=0)
    {
        a[i]=a[i+1];
        i++;
    }
    a[n-1]=0;
}
void f(int a[],int n)
{   //int c=0;

    int x=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=0)
        {a[x]=a[i];
         x++;
        }
    }
    for(int i=x;i<n;i++)
    {  cout<<"dd";
         a[i]=0;
        //if(a[]!=0)c++;
    }
    x=0;
    while(x<n&&a[x]!=0)
    {
        if(a[x+1]==a[x])
        {a[x]=2*a[x];
         shift(a,x+1,n);
        }
        x++;

    }
}
main()
{
    int a[]={10,10,10,10,10,10,10,10,10,10,10};
    f(a,11);
    for(int i=0;i<11;i++)
        cout<<a[i]<<" ";
}
