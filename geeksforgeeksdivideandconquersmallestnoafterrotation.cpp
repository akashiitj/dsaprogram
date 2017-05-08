#include<iostream>
using namespace std;
int n;
int min1(int x, int y) { if (x < y) return x;
                         else return y;
                       }
class searching
{
public:

    int search1(int a[],int low,int high)
    {
      //  int q=6-(high-low+1);
        int mid=(low+high)/2;
        // if (a[(low-1)%n] == a[(mid-1)%n] && a[(high-1)%n] == a[(mid-1)%n])
        //return min1(search1(a, low, mid-1), search1(a, mid+1, high));
         if(a[(mid-1)%n]<a[(mid-2)%n]&&a[(mid-1)%n]<a[(mid)%n])return a[mid-1];
        //else if(mid==low)return a[mid-1];
        else if(a[high-1]>a[mid-1])return search1(a,low,mid-1);
        else return search1(a,mid+1,high);
    }
};
main()
{
    searching so;
    //int n;
    cout<<"enter size of array"<<endl;
    cin>>n;
    int ar[n];
    for(int i=0; i<n; i++)
        cin>>ar[i];//cout<<15/2<<endl;//cout<<(1+8)/2<<2%8;
    cout<<so.search1(ar,1,n)<<endl;
    //cout<<so.search1(6,5);
}
