#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,x,i=2,c=0;
    //cin>>n;
    n=10000000;
    int prex=-1;
    while(n/i>0)
    {
        if(prex!=n/i)c++;
        prex=n/i;
        i++;
    }
    cout<<c;
}
