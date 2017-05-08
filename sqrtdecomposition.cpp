#include<bits/stdc++.h>
using namespace std;
float fsqrt(float x)
{
    float xhalf=0.5f*x;
    int32_t i1=*(int32_t*)&x;
    i1=0x5f375a86-(i1>>1);
    x=*(float*)&i1;
    x=x*(1.5f-xhalf*x*x);
    return 1/x;
}

void update(int a[],int sa[],int dx,int i,int l1)//i is real index
{  a[i]=a[i]+dx;
   sa[i/l1]=sa[i/l1]+dx;

}
int sum1(int a[],int sa[],int i,int l1)
{   int s=0;
    int hv=i/l1;
    for(int j=0;j<hv;j++)
        s=s+sa[j];
    for(int j=hv*l1;j<=i;j++)
        s=s+a[j];
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
    cout<<"enter size of array "<<endl;
    cin>>n;
    int a[n];
    int l1=fsqrt(n);
    int l=n/l1;
    int sa[l+1],sum=0,c=0;
    for(i=0;i<n;i++ )
        { if(i%l1==0)sum=0;
          cin>>a[i];
          sum=sum+a[i];
          if(i%l1==(l1-1))
             {
                 sa[c]=sum;
                 c++;
             }
        }
        sa[c]=sum;
   cout<<sum1(a,sa,9,l1)<<endl;
   update(a,sa,100,4,l1);
    cout<<sum1(a,sa,9,l1)<<endl;
    print(sa,l+1);

}
