#include<iostream>
using namespace std;

void refrence(int *c)
{
    c[4]=89;

}
main()
{ int a[10]={0,0,0,0,0,0,0,0,0,0};
  refrence(a);
  cout<<a[3]<<a[4];
}
