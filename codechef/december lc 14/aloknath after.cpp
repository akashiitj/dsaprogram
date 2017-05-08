#include<bits/stdc++.h>
using namespace std;
main()
{  int x,y,z;
    while(true){
    cin>>x;
    y=x&-x;
    z=x&(-x);
    cout<<y<<" "<<z<<endl;
    }
}
