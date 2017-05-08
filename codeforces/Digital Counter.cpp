#include<bits/stdc++.h>
using namespace std;
main()
{
    int a[10]={2,6,2,3,3,4,2,5,1,2};
    int n;
    cin>>n;
    int x=a[n%10]*a[(n/10)%10];
    cout<<x<<endl;
}

