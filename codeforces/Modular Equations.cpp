#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(b>a)
      {
          cout<<"0"<<endl;
          return 0;
      }
    if(b==a)
    {
        cout<<"infinity"<<endl;
        return 0;
    }
    long long c=0;
    int i=1;
    int x=(a-b)/i;
   int prex=-1;
    while(x>=2)
    {   x=(a-b)/i;
        i++;
        if(prex!=x&&x!=1)
        {
            if((a%x)==b){c++;}
        }
        prex=x;
    }
    if((a%1)==b)c++;
    cout<<c<<endl;
    return 0;
}


