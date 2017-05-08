#include<bits/stdc++.h>
using namespace std;
int main()
{   long long a1[3];
    long long x,y,z,sum=0,a,b;
    for(long long i=0;i<3;i++)
        cin>>a1[i];
    sort(a1,a1+3);
   x=a1[2];
   y=a1[1];
   z=a1[0];
   sum=sum+z;
   x=x-z;
   y=y-z;
   a=min(x,y);
   b=max(x,y);
   if(b>=2*a)sum=sum+a;
   {
       cout<<sum<<endl;
       return 0;
   }
   long long q=b/2;
   sum=sum+q;
   a=a-q;
   if(a>=2&&b%2==1)sum=sum+1;
   cout<<sum<<endl;
   return 0;



}
