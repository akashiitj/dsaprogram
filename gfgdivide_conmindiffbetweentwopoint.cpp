#include<iostream>
#include<math.h>
using namespace std;
int d;
class diffrence
{
public:
    void merging(int a[],int p,int q,int r)
    {
        int i;
        int l[q-p+2],m[r-q+1];
        for(  i=1; i<q-p+2; i++)
            l[i-1]=a[i+p-2];
        l[i-1]=1000000;
        for(  i=1; i<r-q+1; i++)
            m[i-1]=a[i+q-1];
        m[i-1]=1000000;
        int p1=1,p2=1;
        for(int i=p; i<=r; i++)
        {
            if(l[p1-1]<=m[p2-1])
            {
                if((l[p1-1]-m[p2-1])>0)
                {
                    if((l[p1-1]-m[p2-1])<=d)d=(l[p1-1]-m[p2-1]);
                }
                else
                {
                    if((m[p2-1]-l[p1-1])<=d)d=(m[p2-1]-l[p1-1]);
                    }
                a[i-1]=l[p1-1];
                p1++;
            }
            else
            {
                if((l[p1-1]-m[p2-1])>0)
                {
                    if((l[p1-1]-m[p2-1])<=d)d=(l[p1-1]-m[p2-1]);
                }
                else
                {
                    if((m[p2-1]-l[p1-1])<=d)d=(m[p2-1]-l[p1-1]);
                    }
                a[i-1]=m[p2-1];
                p2++;
            }
        }

    }
    void mergesort(int a[],int p,int r)
    {
        if(p<r)
        {
            float e;
            e=floor((p+r)/2);
            int q = (int)e;
            //     cout<<q<<endl;
            mergesort(a, p, q);
            mergesort(a,q+1,r);
            merging(a,p,q,r);
        }
    }
    /* int mindistance(int a[],int x)
     {
         mergesort(a,1,x);
         int d=a[1]-a[0];
         for(int i=1; i<x; i++)
         {
             if(a[i]-a[i-1]<=d)d=a[i]-a[i-1];
         }
     }
     */
};
main()
{
    int n;
    cout<<"enter size of array"<<endl;
    cin>>n;
    int ar[n];
    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
    }
    d=ar[1]-ar[0];
    diffrence do1;
    do1.mergesort(ar,1,n);
    //cout<< do1.mindistance(ar,n)<<endl;
    cout<<d<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<ar[i]<<"   ";
    }
}
