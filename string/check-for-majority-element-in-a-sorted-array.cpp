#include<stdio.h>
int f(int a[],int ml,int x)
{
    int i=0,j=ml-1;
    while(i<=j)
    {
        int mid=(i+j)/2;
        if(a[mid]==x&&(a[mid-1]<a[mid]||mid==0))
            return mid;
        else if(a[mid]>=x)
        {
            j=mid-1;
        }
        else i=mid+1;
        printf("%d%d%d\n",i,j,mid);
    }
}
int main()
{
   int arr[] = {1, 2, 3, 3, 3, 4, 10};
   int n = sizeof(arr)/sizeof(arr[0]);
   int x = 3,i;
   i=f(arr,n,3);
    printf("%d\n",i);
    if(arr[i+(n/2)]==x)printf("%s\n","true");
    else printf("%s\n","false");
   return 0;
}
