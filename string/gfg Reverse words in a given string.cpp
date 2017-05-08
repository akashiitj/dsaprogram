#include<bits/stdc++.h>
using namespace std;
void reverse(string &s,int i,int j)
{
    while(i<j)
    {
        swap(s[i],s[j]);
        i++;
        j--;
    }
}
void mf(string &s)
{   int j,j1,ml=s.length(),i=0;
    reverse(s,0,s.length()-1);
   while(i<ml)
    {    j=i;
        while(s[j]!='\0'&&s[j]!=' ')
        {
            j++;
        }

        reverse(s,i,j-1);
        i=j+1;
    }
}
main()
{
    string s="s    ft";
    mf(s);
    cout<<s;
}
