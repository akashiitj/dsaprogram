#include<bits/stdc++.h>
using namespace std;
main()
{
    long long n,k;
    cin>>n>>k;
    cout<< ((6*n-1)*k)<<endl;
    for(int i=0;i<n;i++)
        cout<<(6*i+1)*k<<" "<<(6*i+2)*k<<" "<<(6*i+3)*k<<" "<<(6*i+5)*k<<endl;
}
