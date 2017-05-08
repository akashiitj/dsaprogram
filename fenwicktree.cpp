#include<bits/stdc++.h>
using namespace std;
void buildft(int a[],int f[],int ml)
{   int j;
    for(int i=1;i<ml;i++)
    {   j=i;
        while(j<ml){
        f[j]=f[j]+a[i];
        j=j+(j&(-j));
    }
    }
}
void update(int a[],int f[],int ml,int p,int dx)
{
    a[p]=a[p]+dx;
    while(p<ml){
        f[p]=f[p]+dx;
        p=p+(p&(-p));
    }

}
int sum(int f[],int i)
{   int s=0;
    while(i>0)
    {
        s=s+f[i];
        i=i-(i&(-i));
    }
    return s;
}
void print(int a[],int ml)
{
    for(int i=0;i<ml;i++ )
        cout<<a[i]<<" ";
        cout<<endl;
}

main()
{
    int n,i;
    cout<<"enter size of ft or array +1"<<endl;
    cin>>n;
    int a[n],f[n];
    for(i=0;i<n;i++ )
        {cin>>a[i];
          f[i]=0;
        }

    buildft(a,f,n);
    print(a,n);
    print(f,n);

    cout<<sum(f,5)<<endl;
   update(a,f,n,2,3);
    print(a,n);
    print(f,n);
    cout<<sum(f,5)<<endl;
}
