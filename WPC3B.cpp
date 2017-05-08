#include<iostream>
using namespace std;
main()
{   int n;
    cin>>n;
    while(n>0)
    {   int n1;
        cin>>n1;
        int sum=0,sum1=0;
        int a[n1];
        for(int i=0;i<n1;i++)
            cin>>a[i];
        for(int i=0;i<n1;i++)
            {if(i<a[i]) {cout<<"NO"<<endl;goto endt;}
             sum=sum+a[i]+(i-a[i]);
             sum1=sum1+i;
            }
        if(sum==sum1)
                cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        endt:
        n--;


    }
}
