#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int a[]={1,2,3,5};
     int l=(sizeof(a)/sizeof(int)),sum=0;
    sort(a,a+l);
    for(int i=l-1;i>=0;i=i-2)
        sum=sum+a[i];
    cout<<sum<<endl;
}
