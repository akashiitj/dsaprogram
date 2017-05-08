#include<iostream>
using namespace std;
int check(int x)
{
    int a[4];
    for(int j=0;j<4;j++)
    {a[3-j]=x%10;
     x=x/10;}
    if(a[0]==a[1]||a[0]==a[2]||a[0]==a[3]||a[1]==a[2]||a[1]==a[3]||a[2]==a[3])return 1;
    else return 2;
}

main(){
    int n;cin>>n;
for(int i=0;i<n;i++)
{   int x;
    cin>>x;
    int d;
    while(x<10000)
    {d=check(x+1);
        if(d==2){cout<<x+1<<endl;break;}
        else x++;
}}}

