#include<bits/stdc++.h>
using namespace std;



int main()
{  int n,m;
  cin>>n>>m;
    map<string,string> name;
    string s1,s2;
    for(int i=0;i<m;i++)
    {
        cin>>s1>>s2;
        if(s1.length()<=s2.length())
            name[s1]=s1;
        else name[s1]=s2;
    }
    string s[n];
    for(int i=0;i<n;i++)
        cin>>s[i];
     for(int i=0;i<n;i++)
        {
            cout<<name[s[i]]<<" ";
        }
        cout<<endl;
  return 0;
}


