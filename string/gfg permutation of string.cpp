#include<bits/stdc++.h>
using namespace std;
void permute(vector<string > &v,string s,int i,int j)
{
    if(i==j)v.push_back(s);
    else{
        for(int x=i;x<=j;x++)
        {
            swap(s[i],s[x]);
            permute(v,s,i+1,j);
             swap(s[i],s[x]);
        }
    }
}

main()
{
    string s;
    cin>>s;
    int i;
    vector<string> v;
    for(i=0;i<s.length();i++)
    {  for(int j=i;j<s.length();j++)
        permute(v,s,i,j);
    }
    sort(v.begin(),v.end());
    for(i=0;i<v.size();i++)
        cout<<v[i]<<endl;
}
