#include<bits/stdc++.h>
using namespace std;
int mod(int x)
{
    return x%1000000007;
}
main()
{
     long long a,b;
     long long x,y;
   cin>>a>>b;
    x=(b*(b-1))/2;
    y=(a*(a+1))/2;
    cout<<mod(mod(x)*mod((mod(y)*mod(b))+mod(a)))<<endl;


}
