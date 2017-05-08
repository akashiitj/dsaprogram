#include <bits/stdc++.h>
using namespace std;
int cf(char c)
{
    if(c=='a'||c=='b'||c=='c')
        return 2;
    if(c=='d'||c=='e'||c=='f')
        return 3;
    if(c=='g'||c=='h'||c=='i')
        return 4;
    if(c=='j'||c=='k'||c=='l')
        return 5;

    if(c=='m'||c=='n'||c=='o')
        return 6;
    if(c=='p'||c=='q'||c=='r'||c=='s')
        return 7;
    if(c=='v'||c=='t'||c=='u')
        return 8;
    if(c=='w'||c=='x'||c=='y'||c=='z')
        return 9;
}

void  f(vector <pair<int,string> > &vn,string s)
{   int l=s.length(),y=0;
    for(int i=0;i<l;i++)
    {
        y=y+(pow(10,l-i-1)* cf(s[i]));
    }
    vn.push_back(make_pair(y,s));
}
main()
{
    vector <pair<int,string> > vn;
    cout<<"enter no of string";
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++)
    {   cin>>s;
        f(vn,s);
    }
    sort(vn.begin(),vn.end());
     for(int i=n-1;i>=0;i--)
    {
         cout<<vn[i].first<<" "<<vn[i].second<<endl;
    }
    //cout<<vn[0].first<<""<<vn[0].second;
}
