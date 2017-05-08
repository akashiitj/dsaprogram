#include<iostream>
using namespace std;
int f(int a[],int ml)//greedy approach
{   int max1=-1,x,c=0;
int j,i=0;
    while(i<ml)
    {   cout<<"d"<<endl;
        max1=-1;
        for( j=i+1;j<=i+a[i];j++)
        {
            if(a[j]+j>max1)
            {
                max1=a[j]+j;
                x=j;
            }
            if(a[j]+j>=ml-1)
                return ++c;

        }
        if(i+1>i+a[i])break;
        c++;
        i=x;
    }
    return -1;
}
 main()
{
    int arr[] = {2, 0, 6, 3, 2, 3, 6, 8, 9, 5};
    cout<<f(arr,10);


}
