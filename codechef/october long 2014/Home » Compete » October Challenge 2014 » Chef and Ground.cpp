#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,t,max1=-9,sum;
    cin>>t;
    while(t>0)
    {   sum=0;
        cin>>n;
        cin>>m;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];

        for(int i=0;i<n;i++)
            {
                if(a[i]>max1)max1=a[i];
            }

        for(int i=0;i<n;i++)
        {
            sum=sum+(max1-a[i]);
        }

        if(((sum-m)%n)==0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        t--;
    }
    return 0;
}
