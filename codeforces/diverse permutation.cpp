#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    int i=1,j=k+1,c=0;
    while(i<=j)
    {
        a[c++]=i++;
        //cout<<i<<endl;
        if(i<=j)
        {
            a[c++]=j--;
          //  cout<<a[c+1]<<endl;
        }

    }
    for(int i=0; i<k+1; i++)
        cout<<a[i]<<" ";

    for(int i=k+2;i<=n;i++)
        cout<<i<<" ";
    cout<<endl;
}
