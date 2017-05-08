#include<stdio.h>
int present_flag;
int binary_search(int array[],int low,int high,int key)
{
    int mid=(high + low)/2;

    if(low>high)
    {
        return -1;
    }

    else if(array[mid]==key)return mid;
      else if(array[mid] >key)
          return binary_search(array,low,mid,key);
        else
          return binary_search(array,mid+1,high,key);


}
main()
{
int array[9],i,n,key;
printf("Enter 9 numbers in asc order \n");
for(i=0;i<9;i++)
scanf("%d",&array[i]);// <--- this should be array[i] and not n.
printf("Enter number to be searched\n");
scanf("%d",&key);
present_flag=binary_search(array,0,8,key);
printf("position %d\n",present_flag);
if (present_flag==-1 )
printf("Number not present in array\n");
}
