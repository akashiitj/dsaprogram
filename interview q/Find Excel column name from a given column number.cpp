#include<bits/stdc++.h>
using namespace std;
main()
{
int a; string s;

//cout<<702/26;
// cout<<char(97)<<" "<<int('a');
while(true){cin>>a;
s="";
while(a>=1)
{
  char c=char(((a-1)%26)+97);
//if(a%26==0)c='z';
  //cout<<c<<endl;
  s=c+s;
  a=(a-1)/26;
}
cout<<s;}
}
