#include<iostream>
using namespace std;

void swap1(int *x,int *y)
{
    int p;
    p=*x;
    *x=*y;
    *y=p;
}

main()
{ int i=20,j=89;
  swap1(&i,&j);
  cout<<i<<"   "<<j;

}
