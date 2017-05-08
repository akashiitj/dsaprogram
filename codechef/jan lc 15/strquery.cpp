#include<bits/stdc++.h>
using namespace std;
void buildft(int a[],int f[],int ml)
{
    int j;
    for(int i=1; i<ml; i++)
    {
        j=i;
        while(j<ml)
        {
            f[j]=f[j]+a[i];
            j=j+(j&(-j));
        }
    }
}
void update(int a[],int f[],int ml,int p,int dx)
{
    a[p]=a[p]+dx;
    while(p<ml)
    {
        f[p]=f[p]+dx;
        p=p+(p&(-p));
    }

}
int sum(int f[],int i)
{
    int s=0;
    while(i>0)
    {
        s=s+f[i];
        i=i-(i&(-i));
    }
    return s;
}
void print(int a[],int ml)
{
    for(int i=0; i<ml; i++ )
        cout<<a[i]<<" ";
    cout<<endl;
}

main()
{   std::ios_base::sync_with_stdio(false);
    int n,i,q;
  //  cout<<"enter size of ft or array +1"<<endl;
    cin>>n>>q;
    string s;
    cin>>s;
    n++;
    int a[n],f[n];
    a[0]=0;
    f[0]=0;
    for(i=1; i<=n; i++ )
    {
        a[i]=s[i-1]-48;
        f[i]=0;
    }

    buildft(a,f,n);

    int wq;
    unsigned long long c=0;
    int x,y,j;
    while(q--)
    {
        cin>>wq;
        if(wq==1)
        {
            cin>>x>>y;
            update(a,f,n, x,y-a[x]);

        }
        else
         {   c=0;
            cin>>x>>y;
            for( i=x;i<=y;i++)
            {
                for( j=i;j<=y;j++)
                    if(((sum(f,j)-sum(f,i-1))%3)==0)c++;
            }
            cout<<c<<endl;

        }

    }
}

