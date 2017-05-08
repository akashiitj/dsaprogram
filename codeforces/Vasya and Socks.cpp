#include<iostream>
using namespace std;
main()
{
    int d,n,m;
    cin>>d>>m;
    n=d/m;
    d=d+n;
    n++;
    while(n*m<=d)
    {
        d++;
        n++;
    }
    cout<<d<<endl;

}
