#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
string s[n];
for(int i=0;i<n;i++)
    cin>>s[i];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int c=0;
            if(i-1>=0&&s[i-1][j]=='o')c++;
            if(i+1<=n-1&&s[i+1][j]=='o')c++;
            if(j+1<=n-1&&s[i][j+1]=='o')c++;
            if(j-1>=0&&s[i][j-1]=='o')c++;
            if(c%2!=0){cout<<"NO"<<endl;return 0;}

        }
    }
    cout<<"YES"<<endl;
    return 0;

}
