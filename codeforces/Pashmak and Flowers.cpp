#include<bits/stdc++.h>
using namespace std;
long long fact(long long n)
{
    if(n==0||n==1)return 1;
    return n*fact(n-1);
}
main()
{
    // cout<<fact(5)<<endl;
    long long n;
    cin>>n;
    long long a[n];
    for(long long i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    long long c1=1,c2=1;
    long long i=0;
    while(i<n-1&&a[i+1]==a[i++])
        c1++;
    i=n-1;
    while(i>0&&a[i-1]==a[i--])
        c2++;
   if(c1==n)cout<<a[n-1]-a[0]<<" "<<(n*(n-1))/2<<endl;
   else cout<<a[n-1]-a[0]<<" "<<c1*c2<<endl;
}


