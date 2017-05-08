#include<iostream>
using namespace std;
int f(int a[],int i,int *c,int vai)//value at i
{
    int x=a[i-1];
    (*c)=(*c)+1;
    if(vai==x)
        return *c;
    f(a,x,c,vai);

}

main()
{
    int a[5]={2,3,1,5,4};
    unsigned long long c=1000000008;
   // cout<<f(a,4,&c,4);
    cout<<1000000007%1<<endl;
}
