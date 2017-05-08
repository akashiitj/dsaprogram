#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sn=0,sp=0,d,sum=0;
    cin>>n;
    int a[n+1];
    a[0]=0;
    cin>>a[1];
    sum=a[1];
    for(int i=2; i<=n; i++)
    {
        cin>>a[i];
        d=a[i-1]-a[i];
        if(d>=0)sp=sp+d;
        else {
          if(sp<=abs(d))  sum=sum+abs(sp+d);
            if(abs(d)>=sp)sp=0;
            else sp=sp+d;

        }
    }


    cout<<sum<<endl;
    return 0;
}
