#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v1,v2,t,d;
    cin>>v1>>v2>>t>>d;
    int ans=v1;
    for(int i=2;i<=t;i++)
    {
        for(int j=d;j>=-d;j--)
        {
            if(abs(v1+j-v2)<=(t-i)*d)
            {
                v1=v1+j;
                ans=ans+v1;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
