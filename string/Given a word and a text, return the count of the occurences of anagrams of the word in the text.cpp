#include<bits/stdc++.h>
using namespace std;
int f(string a,string b)
{
    int x[256]={0};
    for(int i=0;i<a.length();i++)
    {
        x[a[i]]++;
        x[b[i]]--;
    }
    for(int i=0;i<256;i++)
        if(x[i]!=0)return 0;

    return 1;
}

main()
{
    string a;
    string b;
    cin>>a;
    cin>>b;
    int c=0;
    for(int i=0;i<a.length()-b.length()+1;i++)
    {    cout<<a.substr(i,b.length())<<endl;
        c=c+f(a.substr(i,b.length()),b);
    }
    cout<<c<<endl;
}
