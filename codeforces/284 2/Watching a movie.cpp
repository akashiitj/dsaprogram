#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


int main()
{
    int t,n,x;
    double a,b;
    double i1,i2;
    cin>>n>>t;
    ll sum=0;
    double pm=0,pb=-1,ps;
    for(int i=0; i<n; i++)
    {
        cin>>a>>b;
        int bs=b;
        a=a-pm;
        b=b-pm;
      //  cout<<b<<"  b "<<a<<" "<<endl;
        i1=ceil(a/t);
        i2=ceil(b/t);
      //   cout<<i2<<" "<<i1<<" "<<endl;
        sum=sum+(i2-i1)*t+(t-((i2*t)-b));

        pm=bs;

       // cout<<sum<<endl;
    }
    cout<<sum<<endl;
    return 0;
}
