#include<bits/stdc++.h>
using namespace std;
int f(int i,int j)
{
    if(i==j)return 1;
    if(i==1||j==1)
    {
        if(i>j)return i;
        else return j;
    }
    if(i>j)return f(i-j,j)+f(j,j);
    if(j>i)return f(i,j-i)+f(i,i);
}
main()
{
    int t;
    cin>>t;
    int i,j;
    while(t--)
    {  cin>>i>>j;
        cout<<f(i,j)<<endl;
    }
}
