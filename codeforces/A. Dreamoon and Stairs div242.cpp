#include<bits/stdc++.h>
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    if(n<m)cout<<"-1"<<endl;
    else {

        if(n%(2*m)==0)
        {
            n=n/(2*m);
            cout<<n*m<<endl;
        }
        else
        {
            n=n/(2*m);
             cout<<(n+1)*m<<endl;
        }
    }
}
