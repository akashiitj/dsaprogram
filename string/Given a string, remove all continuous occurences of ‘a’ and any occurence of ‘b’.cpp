#include<bits/stdc++.h>
using namespace std;
string f(string &s)
{
    int i=0,j=1;
   while(j<s.length()){
    if(s[j]=='a'&&s[i]=='a')
    {
          j++;
    }
    else if(s[j]=='b')j++;
    else {s[i+1]=s[j];
    i++;j++;
    }
   }
   s.resize(i+1);
   return s;
}
main()
{    string s="aacbccdbsssabaghaaaa";
    cout<<f(s);
}
