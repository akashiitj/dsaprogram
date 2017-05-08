#include<bits/stdc++.h>
using namespace std;
void f(int a[],int ml)
{
    int s[ml],l[ml];
    int mi=0,li=ml-1;//min index,large index
    s[0]=-1;
    l[ml-1]=-1;
    for(int i=1;i<ml;i++)
    {
        if(a[i]<a[mi])
        {
            mi=i;
            s[i]=-1;
        }
        else
            s[i]=mi;
    }
     for(int i=ml-2;i>=0;i--)
    {
        if(a[i]>a[li])
        {
            li=i;
            l[i]=-1;
        }
        else
            l[i]=li;
    }
     for (int i = 0; i < ml; i++)
   {
       if (s[i] != -1 && l[i] != -1)
       {
         cout<<a[s[i]]<<" "<<a[i]<<" "<<a[l[i]]<<endl;
          return;
       }
   }
   cout<<"not"<<endl;

}
int main()
{
    int arr[] = {12, 11, 10, 5, 6, 2, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    f(arr, n);
    return 0;
}
