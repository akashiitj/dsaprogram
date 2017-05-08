#include<iostream>
using namespace std;
class rf
{   public:
    void rf1(int a[],int n)
    {   //int n=a.size();
        for(int i=0;i<n;i++)
        {
            a[a[i]%n]=a[a[i]%n]+n;
        }
    }
};
main()
{   int ar[]={1,2,3,4,1};
    rf rfo;
    rfo.rf1(ar,5);
    for(int i=0;i<5;i++)
        {
           cout<<ar[i]<<"  ";
        }
}
