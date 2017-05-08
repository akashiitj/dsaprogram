#include<bits/stdc++.h>
using namespace std;
int main()
{   int x=5,a,sum=0;
    while(x>0)
    {cin>>a;
     sum=sum+a;
     x--;

    }
    if(sum==0)
    {
        cout<<"-1"<<endl;
     return 0;
    }
    if(sum%5==0){ cout<<sum/5<<endl;return 0;}
     cout<<"-1"<<endl;
     return 0;
}
