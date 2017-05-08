#include<iostream>
using namespace std;
void f(int a[],int ml)
{
    int i=-1,j=ml,c=0;
    while(i<j)
    {   i++;j--;
       //  i=np(a,i);//next non zero no position
        // j=op(a,j);//next 0 position from back side
         while(a[i]==0&&i<ml)
            i++;
         while(a[j]!=0&&j>=0)
            j--;
         if(i<j)
         {
            c++;
            swap(a[i],a[j]);
         }
    }
    cout<<c<<" "<<ml-i<<endl;
}
main()
{
    int a[]={1,2,3,0,0,0};
    f(a,sizeof(a)/4);
}
