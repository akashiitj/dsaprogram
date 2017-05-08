#include<bits/stdc++.h>
using namespace std;
string f(string &s,int i,int j)
{
    s=s.substr(i-1,j-i+1)+s.substr(0,i-1)+s.substr(j);
return s;
}

main()
{   string s="abcdefgh";
    cout<<f(s,2,8);
}
