#include<iostream>
#include<math.h>
#include <algorithm>
using namespace std;
class sorting
{
public:
    //insertion start
    void insertion(int a[],int n)
    {
        int j;
        int key;
        for(int i=2; i<=n; i++)          //best case theta n;
        {                                  //worst and average n*n;
            j=i-1;
            key=a[i-1];
            while (j>0&&key<a[j-1])
            {
                a[j]=a[j-1];
                j--;
            }
            a[j]=key;
        }
    }
    //insertion end
    //selection start
     void selection(int a[],int n)
    {
      for(int i=0;i<n-1;i++)
      {
          for(int j=i+1;j<n;j++)                  //bigoh n*n;all worst, best average;
          {
              if(a[j]<a[i])swap(a[j],a[i]);
          }
      }
    }
    //selection end
    //merge start
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
          else {a[i-1]=m[p2-1];p2++;}
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
    void bubblesort(int a[],int n)
    {
        for(int i=0;i<n-1;i++)
        for(int j=n-1;j>=1+i;j--)
        {
            if(a[j]<a[j-1])
            {
                int v=a[j];
                a[j]=a[j-1];
                a[j-1]=v;
            }
        }
    }

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
//    int length=sizeof ar[];if we make array of 4 element it give size =16;
    // cout<<sizeof ar<<endl;
    cout<<"enter which sort you wanted to done";
    string s;
   cin >>s;

    sorting so;
    if(s=="insertion")so.insertion(ar,n);
    else if(s=="mergesort")so.mergesort(ar,1,n);
    else if(s=="b")so.bubblesort(ar,n);  //so.insertion(ar,n);
    for(int i=0; i<n; i++)
    {
        cout<<ar[i]<<"   ";
    }
}
/*analysis of merge sort
(1) T(1) = 1

(2) T(N) = 2T(N/2) + N

Next we will solve this recurrence relation. First we divide (2) by N:

(3) T(N) / N = T(N/2) / (N/2) + 1;
Hence the complexity of the MergeSort algorithm is O(NlogN).
*/
