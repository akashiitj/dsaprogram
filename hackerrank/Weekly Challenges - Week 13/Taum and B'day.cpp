#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;
const int N = 10000001;
const int mod = 1000000007;

int main()
{   std::ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
       ll b,w;
       ll x,y,z;
       cin>>b>>w;
       cin>>x>>y>>z;
       ll sum=0;
       if(abs(x-y)<=z)
       {  sum=(b*x)+(w*y);
           cout<<sum<<endl;
           continue;
       }
      if(x<y)
      {
         sum=sum+ x*b;
         sum=sum+w*(x+z);
      }
      else{
        sum=sum+ y*w;
         sum=sum+b*(y+z);
      }
       cout<<sum<<endl;
    }
    return 0;
}

