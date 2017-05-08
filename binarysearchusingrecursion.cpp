#include<iostream>
using namespace std;
int a[9]= {1,3,3,3,3,3,3,3,3};
int bs(int se,int i,int j)
{  if(i>j)return -1;
    int mid;
    mid=(i+j)/2;
    if(se==a[mid])
    {
       // if(mid>0&&a[mid]==a[mid-1])//for finding first occurence of element
         //   return bs(se,i,mid-1);//first occurence
        if(mid<j&&a[mid]==a[mid+1])//for finding last occurence of element
            return bs(se,mid+1,j);//last occurence
        else return mid;
    }
    else  if (se>a[mid])
    {
           return bs(se,mid+1,j);
    }
    else  return bs(se,i,mid-1);

}
main()
{
    //  int a[5]={1,2,3,4,5};
   cout<< bs(3,0,8);
}
