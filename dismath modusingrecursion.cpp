#include<iostream>
using namespace std;
class mod
{   public:
    int findmod(int x,int n,int m)
    {
        if(n==1)return x%m;
        else return ((findmod(x,n-1,m)*findmod(x,1,m))%m);
    }
};
main()
{
    mod mo;
    cout<<mo.findmod(2,5,3);
}
