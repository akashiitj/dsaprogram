#include<iostream>
using namespace std;
int f(int a[],int ml)
{   int x=0,y=0;
    int cmax=a[0];//current max
    int omax=a[0];//overall max
    for(int i=1;i<ml;i++)
    {   if(a[i]>=cmax+a[i])
         x=i;
        cmax=max(cmax+a[i],a[i]);
        if(omax<=cmax)y=i;
        omax=max(cmax,omax);
    }
    cout<<x<<" "<<y<<endl;
    return omax;
}
main()
{    int a[] =  {2, 31, 4, 1, 2, 1, 50, 3};
   int n = sizeof(a)/sizeof(a[0]);
    cout<<f(a,n);
}
