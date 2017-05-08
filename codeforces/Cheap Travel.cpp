#include<bits/stdc++.h>
using namespace std;
main()
{   float n,m,a,b,sum=0;
    cin>>n>>m>>a>>b;
   // cout<<b/m<<endl;
    if(b/m>=a)sum=sum+n*a;
    else{
        int q=n/m;
        int mod=(int)n%(int)m;
        sum=sum+q*b;
        if((mod*a)<=b)
        sum=sum+mod*a;
        else sum=sum+b;
    }
    cout<<(int)sum<<endl;
}
