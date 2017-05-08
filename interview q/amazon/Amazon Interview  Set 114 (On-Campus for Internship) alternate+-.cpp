#include<iostream>
using namespace std;
int ionp(int a[],int ml,int i)//next positive no index after i
{
    while(i<ml)
    {
        if(a[i+1]>0)
            return i+1;
        i++;
    }
    return -1;
}
int ionn(int a[],int ml,int i)//next negative no index after i
{
    while(i<ml)
    {
        if(a[i+1]<0)
            return i+1;
        i++;
    }
    return -1;
}
void insert(int a[],int i,int j)
{
    int x=a[j];
    for(int q=j; q>i; q--)
        a[q]=a[q-1];
    a[i]=x;
}
void rearrange(int a[],int ml)
{
    int np=ionp(a,ml,-1);
    int nn=ionn(a,ml,-1);
    cout<<np<<" "<<nn<<endl;
    for(int i=0; i<ml; i++)
    {
        if(i%2==0)
        {   if(np!=i)
            {   insert(a,i,np);
                np=ionp(a,ml,np);
                nn=ionp(a,ml,i);
            }
            else  np=ionp(a,ml,np);
            cout<<"ionp "<<np<<endl;
            for(int i=0; i<ml; i++)
                cout<<a[i]<<" ";
            cout<<endl;
        }
        else
        {   if(nn!=i)
            {   insert(a,i,nn);
                np=ionp(a,ml,i);
                nn=ionn(a,ml,nn);
            }
            else nn=ionp(a,ml,nn);
            cout<<"ionn "<<nn<<endl;
            for(int i=0; i<ml; i++)
                cout<<a[i]<<" ";
            cout<<endl;
        }
        if(nn==-1||np==-1)
            return ;
    }

}
main()
{
    int n,i,c1,c2;
    c1=-1;
    c2=-1;
    cout<<"enter no. of ele "<<endl;
    cin>>n;
    int a[n];
    for(i=0; i<n; i++)
        cin>>a[i];
   // cout<<ionn(a,5,4)<<endl;
   rearrange(a,n);
    for(i=0; i<n; i++)
        cout<<a[i]<<endl;

}
