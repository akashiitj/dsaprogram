#include<bits/stdc++.h>
using namespace std;
void print(int a[],int ml)
{   for(int i=0;i<ml;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
void f(int a[],int ml)
{
    int i=0,c=0,c1=0,j=ml-1;
    while(i<j)
    {
        while(a[i]!=0)
        {
            i++;
            c++;
        }
        while(a[j]==0)
            j--;
        if(i<j){
        c1++;
        swap(a[i],a[j]);
        i++;
        j--;}
         cout<<c<<" "<<c1<<endl;
     print(a,ml);
    }
    cout<<c+c1<<" "<<c1<<endl;
}

main()
{   int a[9]={1,9,8,0,0,-2,0,1,6};
    f(a,9);
}
