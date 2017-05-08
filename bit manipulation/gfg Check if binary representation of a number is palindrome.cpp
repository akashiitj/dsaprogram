#include<iostream>
using namespace std;
int kthbit(unsigned int x,int p)//position
{   int v=x&(1<<p-1);
    if(v==0)return 0;
    else return 1;

}
int main()
{
    unsigned int r=1;
    unsigned int l=sizeof( unsigned int )*8;
     unsigned int x = 10;

cout<<x1<<endl;
    while(r<l)
    {
        if(kthbit(x,r)!=kthbit(x,l))
        {  cout<<"not"<<endl;
            return 0;
        }
        else r++;l--;

    }
     cout<<"yes"<<endl;
return 0;
}
