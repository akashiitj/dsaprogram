#include<iostream>
using namespace std;
int i,n,s=1000001,l,a[9];
int main()
{
    cin>>n;
    while(cin>>a[i++]) s=min(s,a[i-1]);
    l=n/s;
    if(!l)cout<<-1;
    while(l--) for(i=8; i>=0; i--)
            if((n-a[i])>=l*s && n>=a[i])
            {
                cout<<i+1;
                n-=a[i];
                break;
            }
    return 0;
}
