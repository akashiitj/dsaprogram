#include<iostream>
using namespace std;
 int f(int a[],int ml)
 {
     int t1=a[0],t2=t1;
     for(int i=1;i<ml;i++)
     {
         if(a[i]>t2)
         {
             t2=t1;
             t1=a[i];
         }
         else if(a[i]>t2)
            t2=a[i];
         else{}
     }
     return t2;
 }
main()
{
    int a[]={4,2,7,45,1};
    cout<<f(a,5);
}
