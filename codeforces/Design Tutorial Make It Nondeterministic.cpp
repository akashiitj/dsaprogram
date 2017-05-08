#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    cin>>n;
    string s[n][2],x;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<2; j++)cin>>s[i][j];
    }
    int a[n];

    for(int i=0; i<n; i++)
    {
        cin>>q;
        a[i]=q-1;
    }

    x=min(s[a[0]][0],s[a[0]][1]);

    for(int i=1; i<n; i++)
    {
        if(min(s[a[i]][0],s[a[i]][1])>x)
            x=min(s[a[i]][0],s[a[i]][1]);
        else if(max(s[a[i]][0],s[a[i]][1])>x)
            x=max(s[a[i]][0],s[a[i]][1]);
        else
        {
            cout<<"NO"<<endl;
            return 0;
        }

    }
    cout<<"YES"<<endl;
    return 0;
}
