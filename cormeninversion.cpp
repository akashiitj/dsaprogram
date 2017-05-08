#include<iostream>
using namespace std;
class inversion
{  public:
   int paircounting(int a[],int n)
   {   int c=0;
       for(int i=2;i<=n;i++)
       {   int j=i-1;
           while(j>0)
           {
               if(a[j-1]>a[i-1])c++;
               j--;
           }
       }
   return c;
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
    inversion io;
    cout<<"no of inversion pair is "<<io.paircounting(ar,n);
}
