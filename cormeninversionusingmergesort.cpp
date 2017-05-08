#include<iostream>
#include<math.h>
using namespace std;
int c=0;
class inversion
{
public:

    void merging(int a[],int p,int q,int r)
    {  int i;
      int l[q-p+2],m[r-q+1];
      for(  i=1;i<q-p+2;i++)
                l[i-1]=a[i+p-2];
                l[i-1]=1000000;
      for(  i=1;i<r-q+1;i++)
                m[i-1]=a[i+q-1];
                m[i-1]=1000000;
      int p1=1,p2=1;
      for(int i=p;i<=r;i++)
      {
          if(l[p1-1]<=m[p2-1]){a[i-1]=l[p1-1];p1++;}
          else {a[i-1]=m[p2-1];p2++;if(p1<=q-p+1)c=c+q-p1-p+2;}
      }

    }
    void mergesort(int a[],int p,int r)
    {
        if(p<r)
        {
          float e;
          e=floor((p+r)/2);
          int q = (int)e;
          cout<<q<<endl;
          mergesort(a, p, q);
          mergesort(a,q+1,r);
          merging(a,p,q,r);

        }
    }
};
 main(){
 int n;
    cout<<"enter size of array"<<endl;
    cin>>n;
    int ar[n];
    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
    }
//    int length=sizeof ar[];if we make array of 4 element it give size =16;
    // cout<<sizeof ar<<endl;


    inversion io;

    io.mergesort(ar,1,n);
    //else if(s=="b")so.bubblesort(ar,n);  //so.insertion(ar,n);
    for(int i=0; i<n; i++)
    {
        cout<<ar[i]<<"   ";
    }
    cout<<c<<endl;
}
