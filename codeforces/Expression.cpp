#include<bits/stdc++.h>
using namespace std;
 main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int sum=a+(b*c);
    if(sum<a*(b+c))sum=a*(b+c);
    if(sum<a*b*c)sum=a*c*b;
    if(sum<(a+b)*c)sum=(a+b)*c;
     if(sum<(a+b)+c)sum=(a+b)+c;
     if(sum<(a*b)+c)sum=(a*b)+c;
     cout<<sum<<endl;

}
