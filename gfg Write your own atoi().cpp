#include<iostream>
#include<math.h>
using namespace std;

main()
{
    char ar[]="23458";
    int sum=0;
    int l=sizeof(ar)-1;
    //cout<<l<<endl;
    //cout<<ar[2]*pow(10,0)<<endl;;
    for(int i=0; i<l; i++)
    {
        sum=sum+(ar[l-1-i]-48)*pow(10,i);
        cout<<int(pow(10,i))<<"  "<<sum<<endl;
    }
    cout<<sum;
}
