#include<iostream>
#include<math.h>
using namespace std;
int a[100];
void merge1(int *a,int in,int mn,int ln)
{
    int n1,n2;
    n1=mn-in+1;
    n2=ln-mn;
    int a1[n1],a2[n2];
    for(int i=0; i<n1; i++)a1[i]=a[in+i];
    for(int i=0; i<n2; i++)a2[i]=a[mn+1+i];
    //a1[n1]=1000000;a2[n2]=12000000;
    int m=0,n=0;
    for(int i=in; i<=ln; i++)
    {
        if(m<n1&&n<n2)
        {
            if(a1[m]<a2[n])
            {
                a[i]=a1[m];
                m++;
            }
             //else if(a1[m]==a2[n]){a[i]=a2[n];m++;n++;}
            else
            {
                a[i]=a2[n];
                n++;
            }
        }
        else if(m>=n1&&n<n2)
        {
            a[i]=a2[n];
            n++;
        }
        else if(m<n1&&n>=n2)
        {
            a[i]=a1[m];
            m++;
        }
    }
}
void mergesort(int *a,float p,float r)
{
    float q;
    if(p<r)
    {
        q=floor((p+r)/2);//cout<<q<<endl;
        mergesort(a,p,q);
        mergesort(a,q+1,r);
        // int s=p,d=q,f=r;
        merge1(a,p,q,r);
    }

}

main()
{
    cout<< "enter no of elemaent in array";
    int o;
    cin>>o;
    for(int i=0; i<o; i++)cin>>a[i];
    mergesort(a,0,o-1);
    for(int i=0; i<o; i++)cout<<a[i]<<"   ";
}

