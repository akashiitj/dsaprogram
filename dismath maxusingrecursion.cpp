#include<iostream>
using namespace std;
class fm
{
public:
    int findmax(int a[],int ml)
    {      int t;
        if((ml)==2)
        {
            if(a[ml-1]>=a[ml-2])return a[ml-1];
            else return a[ml-2];
        }
        else
        {t=findmax(a,ml-1);
        if(t>=a[ml-1])return t;
        else return a[ml-1];
        }
    }
};
main()
{
    int ar[]={2,3,4,5,6,3,67};
    fm fmo;
    cout<<fmo.findmax(ar,7);
}
