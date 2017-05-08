#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,m,a,t,c;
    cin>>t;
    while(t--)
    {
    c=1;
    cin>>n>>m>>a;
    while(n>(a*a))
    {
        c++;
        n=n-(a*a);
    }
    cout<<c<<" "<<n<<endl;
    cout<<((m*a)+c)*a*a<<endl;
    }

}
